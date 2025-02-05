#include <memory>

#include <QApplication>

#include "mewmintapplication.h"

#include <init/mewmint.h>
#include <interfaces/handler.h>
#include <interfaces/init.h>
#include <interfaces/node.h>
#include <node/context.h>
#include <util/system.h>
#include <util/translation.h>

#include <qt/bitcoin.h>
#include <qt/initexecutor.h>

namespace init {

class MewmintQtInit : public MewmintInit
{
public:
    MewmintQtInit(const std::string& arg_chain_type) : MewmintInit(arg_chain_type) {}

    bool Initialize() override
    {
        return MewmintInit::Initialize();
    }

    void Interrupt() override
    {
        MewmintInit::Interrupt();
    }

    void Shutdown() override
    {
        MewmintInit::Shutdown();
    }

    void handleRunawayException(const std::exception* e) override
    {
        PrintExceptionContinue(e, "Runaway exception");
        QMessageBox::critical(nullptr, QObject::tr("Runaway exception"),
            QObject::tr("A fatal error occurred. %1 can no longer continue safely and will quit.").arg(PACKAGE_NAME) +
            QLatin1String("\n\n") + QString::fromStdString(strMiscWarning));
        exit(EXIT_FAILURE);
    }

    void setupServerArgs() override { return SetupServerArgs(*this); }

    bool baseInitialize() override
    {
        return MewmintInit::baseInitialize();
    }

    UniValue executeInitCommands() override
    {
        return MewmintInit::executeInitCommands();
    }
};

} // namespace init

int main(int argc, char* argv[])
{
#ifdef WIN32
    util::WinCmdLineArgs winArgs;
    std::tie(argc, argv) = winArgs.get();
#endif

    std::unique_ptr<interfaces::Init> init = interfaces::MakeGuiInit(argc, argv);

    SetupEnvironment();

    std::unique_ptr<init::MewmintQtInit> app_init = std::make_unique<init::MewmintQtInit>(init::NetworkToString(gArgs.GetChainType()));
    app_init->setupServerArgs();

    // Do not refer to data directory yet, this can be overridden by Intro::pickDataDirectory

    /// 1. Basic Qt initialization (not dependent on parameters or configuration)
    Q_INIT_RESOURCE(mewmint);
    Q_INIT_RESOURCE(mewmint_locale);

    MewmintApplication app;
    app.setApplicationName(PACKAGE_NAME);
    app.setOrganizationDomain("mewmint.org");
    app.setQuitOnLastWindowClosed(false);

    /// 2. Parse command-line options. These take precedence over anything else.
    // Command-line options take precedence:
    app_init->ParseParameters(argc, argv);

    /// 3. Application identification
    // must be set before OptionsModel is initialized or translations are loaded,
    // as it is used to locate QSettings
    app.setApplicationName(PACKAGE_NAME);

    /// 4. Initialization of translations, so that intro dialog is in user's language
    // Now that settings and translations are available, ask user for data directory
    // User language is set up: pick a data directory
    bool did_show_intro = false;
    bool prune = false; // Intro dialog prune check box
    void* node = nullptr;
    bool try_again = true;
    while (try_again) {
        try_again = false;
        node = app_init->createNode();
        if (!node) {
            if (did_show_intro) {
                // If the intro dialog was shown and there is no node it means the user requested a prune size
                // that is too small, show an error.
                QMessageBox::critical(nullptr, PACKAGE_NAME,
                    QObject::tr("Error: Specified data directory \"%1\" is too small. Please use a larger data directory.").arg(QString::fromStdString(gArgs.GetArg("-datadir", ""))));
                return EXIT_FAILURE;
            }
            did_show_intro = true;
            try_again = true;
            continue;
        }
    }
    if (!node) return EXIT_FAILURE;

    // Create and start the executor
    InitExecutor* executor = new InitExecutor(node, app_init.get());
    return app.exec();
}
