include $(top_srcdir)/src/Makefile.include

AM_CPPFLAGS += -I$(top_srcdir)/src
AM_CPPFLAGS += -I$(top_srcdir)/src/test
AM_CPPFLAGS += $(BDB_CPPFLAGS)
AM_CPPFLAGS += $(BOOST_CPPFLAGS)
AM_CPPFLAGS += $(CRYPTO_CFLAGS)

# Test binary
bin_PROGRAMS = test_mewmint

# Test suite
TESTS =

if BUILD_BITCOIN_TESTS
  TESTS += test_mewmint
endif

TEST_SRCDIR = $(abs_top_srcdir)/test
TEST_BINARY = test_mewmint$(EXEEXT)

EXTRA_DIST = $(TEST_SRCDIR)

if !ENABLE_FUZZ
  # Test binary sources
  test_mewmint_SOURCES = \
    test/main.cpp \
    test/util/setup_common.cpp

  # Test binary flags and libraries
  test_mewmint_CPPFLAGS = $(AM_CPPFLAGS)
  test_mewmint_LDADD = $(LIBBITCOIN_SERVER)
  test_mewmint_LDADD += $(LIBBITCOIN_CLI)
  test_mewmint_LDADD += $(LIBBITCOIN_COMMON)
  test_mewmint_LDADD += $(LIBBITCOIN_UTIL)
  test_mewmint_LDADD += $(LIBBITCOIN_CONSENSUS)
  test_mewmint_LDADD += $(LIBBITCOIN_CRYPTO)
  test_mewmint_LDADD += $(LIBUNIVALUE)
  test_mewmint_LDADD += $(LIBLEVELDB)
  test_mewmint_LDADD += $(LIBMEMENV)
  test_mewmint_LDADD += $(BOOST_LIBS)
  test_mewmint_LDADD += $(CRYPTO_LIBS)
  test_mewmint_LDADD += $(MINIUPNPC_LIBS)
  test_mewmint_LDADD += $(EVENT_LIBS)
  test_mewmint_LDADD += $(EVENT_PTHREADS_LIBS)
  test_mewmint_LDADD += $(BDB_LIBS)
  test_mewmint_LDADD += $(SSL_LIBS)
  test_mewmint_LDADD += $(CRYPTO_LIBS)
endif

CLEANFILES = *.gcda *.gcno $(TESTS)
