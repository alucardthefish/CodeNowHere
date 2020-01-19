#!/bin/sh

case `uname` in Darwin*) glibtoolize --copy ;;
  *) libtoolize --copy ;; esac

aclocal && autoheader && automake --add-missing && autoconf
