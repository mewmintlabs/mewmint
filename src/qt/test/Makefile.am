include $(top_srcdir)/src/Makefile.include

AM_CPPFLAGS += $(BDB_CPPFLAGS)
AM_CPPFLAGS += -I$(top_srcdir)/src
AM_CPPFLAGS += -I$(top_builddir)/src/qt
AM_CPPFLAGS += $(QT_INCLUDES)
AM_CPPFLAGS += $(PROTOBUF_CFLAGS)

TESTS =
TESTS_QT =

TEST_QT_MOC_CPP =

if ENABLE_WALLET
if ENABLE_QT_TESTS
  TESTS += $(TESTS_QT)
endif
endif

CLEANFILES = *.gcda *.gcno $(TEST_QT_MOC_CPP)
