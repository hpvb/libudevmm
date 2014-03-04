ACLOCAL_AMFLAGS = -I m4

AM_CFLAGS = $(DEPS_CFLAGS)

lib_LTLIBRARIES = libudevmm/libudevmm.la
libudevmm_libudevmm_la_SOURCES = \
 libudevmm/device.cpp\
 libudevmm/enumerator.cpp\
 libudevmm/enumerator_iterator.cpp
 libudevmm_libudevmm_la_LDFLAGS = $(DEPS_LIBS)
libudevmm_libudevmm_la_CPPFLAGS = -Iinclude

include_HEADERS = include/libudevmm.hpp
udevmmincludedir = $(includedir)/libudevmm
udevmminclude_HEADERS = include/libudevmm/device.hpp

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libudevmm-1.0.pc

noinst_PROGRAMS = exampleProgram/exampleProgram
exampleProgram_exampleProgram_SOURCES = exampleProgram/exampleProgram.cpp
exampleProgram_exampleProgram_LDFLAGS = $(DEPS_LIBS) libudevmm/libudevmm.la
exampleProgram_exampleProgram_CPPFLAGS = -Iinclude
