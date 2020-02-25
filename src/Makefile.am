AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_FLAGS)

bin_PROGRAMS = cnh

cnh_SOURCES = ../Main.cpp CodeNowHere.cpp docopt.cpp ../headers/CodeNowHere.h ../headers/docopt.h ../headers/docopt_private.h ../headers/docopt_util.h ../headers/docopt_value.h ../headers/Helper.h ../headers/ICommandBehavior.h ../headers/OnlyFileBehavior.h ../headers/ManyFileBehavior.h ../headers/BunchFileBehavior.h Helper.cpp ICommandBehavior.cpp OnlyFileBehavior.cpp ManyFileBehavior.cpp BunchFileBehavior.cpp

cnh_infodir = $(datadir)/cnh
skivvy_manualsdir = $(datadir)/skivvy

# Set a macro for your code to use
cnh_CXXFLAGS = -DDATA_LOCATION=\"$(datadir)/cnh\"

# This will install it from the development directories
cnh_info_DATA = $(top_srcdir)/extdata/InlineComments.txt $(top_srcdir)/extdata/lang.dat $(top_srcdir)/extdata/*.tpl

# make sure it gets in the installation package
EXTRA_DIST = ../extdata/InlineComments.txt ../extdata/lang.dat ../extdata/*.tpl