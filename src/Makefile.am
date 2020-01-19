AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_FLAGS)

bin_PROGRAMS = cnh

#cnh_SOURCES = Main.cpp CodeNowHere.cpp ../headers/CodeNowHere.h
cnh_SOURCES = ../Main.cpp CodeNowHere.cpp ../headers/CodeNowHere.h

cnh_infodir = $(datadir)/cnh
skivvy_manualsdir = $(datadir)/skivvy

# Set a macro for your code to use
cnh_CXXFLAGS = -DDATA_LOCATION=\"$(datadir)/cnh\"

# This will install it from the development directories
cnh_info_DATA = $(top_srcdir)/extdata/InlineComments.txt $(top_srcdir)/extdata/lang.dat $(top_srcdir)/extdata/*.tpl

# make sure it gets in the installation package
extra_DIST = $(top_srcdir)/extdata/InlineComments.txt $(top_srcdir)/extdata/lang.dat $(top_srcdir)/extdata/*.tpl
