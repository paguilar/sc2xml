dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.67)

m4_define(sc2xml_major_version,  0)
m4_define(sc2xml_minor_version,  0)
m4_define(sc2xml_micro_version,  2)
m4_define(sc2xml_version, sc2xml_major_version.sc2xml_minor_version.sc2xml_micro_version)

AC_INIT([sc2xml], [sc2xml_version], [http://www.paguilar.org/blog], [sc2xml], [http://www.paguilar.org/blog])

AC_CONFIG_HEADERS([config.h])


AM_INIT_AUTOMAKE([-Wall])

dnl Checks for programs
AC_PROG_CC
AC_PROG_RANLIB
AC_PROG_INSTALL

dnl Determine if a usable lex is available on this system
AM_PROG_LEX
if [[ "$LEX" != "flex" ]]; then
	AC_MSG_ERROR(flex is required to create the sc2xml scanner)
fi

dnl Determine if a usable yacc is available on this system
AC_PROG_YACC
AC_CHECK_PROG(HAVE_YACC, $YACC, yes, no)
if [[ "$HAVE_YACC" = "no" ]]; then
	AC_MSG_ERROR($YACC is not usable as yacc - consider using bison)
fi


AC_CHECK_HEADERS([inttypes.h libintl.h malloc.h stddef.h stdlib.h string.h unistd.h])

AC_CHECK_FUNCS([memset])

dnl ================================================================
dnl Configure switches
dnl ================================================================

dnl
dnl Debugging
dnl 
AC_ARG_ENABLE([debug],
   	[  --enable-debug		Enable debug (default: no)],
   	[case "${enableval}" in
		yes) ac_enable_debug=yes ;;
		no)  ac_enable_debug=no ;;
		*) AC_MSG_ERROR([bad value ${enableval} for --enable-debug]) ;;
		esac],
	[ac_enable_debug=no])
if test "x${ac_enable_debug}" = xyes ; then
    AC_DEFINE([DEBUG_INFO], [], [Output debug])
fi

dnl ================================================================
dnl Conditionals
dnl ================================================================


dnl ================================================================
dnl pkg-config checks
dnl ================================================================

PKG_CHECK_MODULES(GLIB2, [
    glib-2.0 >= 2.18.0
    gthread-2.0 >= 2.13.0
])

PKG_CHECK_MODULES(LIBXML2, [
	libxml-2.0 >= 2.5.0
])

SC2XML_CFLAGS="$LIBXML2_CFLAGS $GLIB2_CFLAGS"
SC2XML_LIBS="$LIBXML2_LIBS $GLIB2_LIBS"

AC_SUBST(SC2XML_LIBS)
AC_SUBST(SC2XML_CFLAGS) 

dnl Use -Wall if we have gcc.
if test "x$ac_cv_prog_gcc" = xyes ; then
  #CFLAGS="$CFLAGS -Wall"
  CFLAGS="-g -Wall"
fi

AC_CONFIG_FILES([
	Makefile
	src/Makefile
])
AC_OUTPUT

AC_MSG_RESULT([
************************************************************
Simple C to XML Serializer $VERSION:

Configuration summary:

	Debug: ....... ${ac_enable_debug}

Installation directories:

	Program: ............. ${prefix}/bin

************************************************************

  Type 'make' to compile SC2XML.

  Type 'make install' to install SC2XML. 
  
************************************************************
])

