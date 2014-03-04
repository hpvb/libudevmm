ACLOCAL_AMFLAGS = -I m4

lib_LTLIBRARIES = libudevmm/libudevmm.la
libudevmm_libudevmm_la_SOURCES = libudevmm/libudevmm.cpp
libudevmm_libudevmm_la_LDFLAGS = 
libudevmm_libudevmm_la_CPPFLAGS = -Iinclude

include_HEADERS = include/libudevmm.hpp

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libudevmm-1.0.pc

noinst_PROGRAMS = exampleProgram/exampleProgram
exampleProgram_exampleProgram_SOURCES = exampleProgram/exampleProgram.cpp
exampleProgram_exampleProgram_LDFLAGS = libudevmm/libudevmm.la
exampleProgram_exampleProgram_CPPFLAGS = -Iinclude
