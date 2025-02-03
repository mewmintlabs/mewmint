#ifndef MEWMINT_NETCONFIG_H
#define MEWMINT_NETCONFIG_H

namespace NetConfig {
    // Network magic numbers
    static const unsigned char MAINNET_MESSAGE_START[4] = {0xf9, 0xbe, 0xb4, 0xd9}; // Mewmint mainnet
    static const unsigned char TESTNET_MESSAGE_START[4] = {0x0b, 0x11, 0x09, 0x07}; // Mewmint testnet
    static const unsigned char SIGNET_MESSAGE_START[4] = {0x0a, 0x03, 0xcf, 0x40}; // Mewmint signet
    static const unsigned char REGTEST_MESSAGE_START[4] = {0xfa, 0xbf, 0xb5, 0xda}; // Mewmint regtest

    // Default ports
    static const int MAINNET_PORT = 8333;        // Mainnet port
    static const int MAINNET_RPC_PORT = 8332;    // Mainnet RPC port
    static const int TESTNET_PORT = 18333;       // Testnet port
    static const int TESTNET_RPC_PORT = 18332;   // Testnet RPC port
    static const int SIGNET_PORT = 38333;        // Signet port
    static const int SIGNET_RPC_PORT = 38332;    // Signet RPC port
    static const int REGTEST_PORT = 18444;       // Regtest port
    static const int REGTEST_RPC_PORT = 18443;   // Regtest RPC port

    // Seed nodes for mainnet
    static const char* const MAINNET_SEEDS[] = {
        "seed1.mewmint.org",
        "seed2.mewmint.org",
        "seed3.mewmint.org",
        "seed4.mewmint.org",
        nullptr
    };

    // Seed nodes for testnet
    static const char* const TESTNET_SEEDS[] = {
        "testnet-seed1.mewmint.org",
        "testnet-seed2.mewmint.org",
        "testnet-seed3.mewmint.org",
        nullptr
    };

    // Seed nodes for signet
    static const char* const SIGNET_SEEDS[] = {
        "signet-seed1.mewmint.org",
        "signet-seed2.mewmint.org",
        nullptr
    };
} // namespace NetConfig

#endif // MEWMINT_NETCONFIG_H
