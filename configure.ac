dnl Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([libudevmm],[1.0])
AC_PROG_CC

AC_CANONICAL_TARGET
AC_PROG_CXX
AC_LANG([C++])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([-Wall subdir-objects])
AM_PROG_CC_C_O 

AM_PROG_AR
LT_INIT([disable-static])
LT_INIT

CXXFLAGS="${CXXFLAGS} -std=c++11 -O3 -Wall -Wextra -Werror -g3"
AC_SUBST([AM_CXXFLAGS])

PKG_CHECK_MODULES([DEPS], [libudev])

AC_CONFIG_FILES(Makefile
                libudevmm-1.0.pc)
AC_OUTPUT