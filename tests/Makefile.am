check_LTLIBRARIES = libgtest.la
libgtest_la_SOURCES = ../googletest/googletest/src/gtest-all.cc
libgtest_la_CPPFLAGS = -I$(top_srcdir)/googletest/googletest/include -I$(top_srcdir)/googletest/googletest

check_PROGRAMS = AllTests
AllTests_SOURCES = AllTests.cpp ../src/ICommandBehavior.cpp ../src/OnlyFileBehavior.cpp ../src/Helper.cpp ../src/cnh_structs.cpp
AllTests_LDADD = libgtest.la
AllTests_LDFLAGS = -pthread
AllTests_CPPFLAGS = -I$(top_srcdir)/googletest/googletest/include -I$(top_srcdir)/src

#another_test_SOURCES = another_test.cpp
#another_test_LDADD = libgtest.la
#another_test_LDFLAGS = -pthread
#another_test_CPPFLAGS = -I$(top_srcdir)/googletest/googletest/include -I$(top_srcdir)/src

TESTS = AllTests