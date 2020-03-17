#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([cnh], [2.1.1], [sergiop18@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror subdir-objects])
#AC_CONFIG_SRCDIR([src/Main.cpp])
AC_CONFIG_SRCDIR([Main.cpp])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIRS([m4])
AM_PROG_AR

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.
LT_INIT
AC_ENABLE_SHARED
AC_DISABLE_STATIC
AC_PROG_LIBTOOL(libtool)

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
AC_CONFIG_FILES([Makefile src/Makefile headers/Makefile extdata/Makefile tests/Makefile])
AC_OUTPUT
