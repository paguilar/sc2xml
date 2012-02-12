
AM_CPPFLAGS = $(SC2XML_CFLAGS)

AM_CFLAGS = -DSYSCONFDIR=\"$(sysconfdir)\"

bin_PROGRAMS = sc2xml

sc2xml_LDADD = $(SC2XML_LIBS)
sc2xml_SOURCES = misc.h xml.h sc2xml.h parser.tab.h scanner.l parser.y misc.c xml.c main.c

