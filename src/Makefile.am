#
# Makefile.am
#

#AM_LDFLAGS = -Wl,--gc-sections -Wl,--as-needed
AM_CFLAGS = ${my_CFLAGS}

bin_PROGRAMS = food_tracker

food_tracker_SOURCES =            \
	main.c    	        \
	gui.c			\
	common.h		\
	gettext.h

food_tracker_CFLAGS = $(AM_CFLAGS)\
	$(LIBGTK_CFLAGS)	\
	$(LIBCONFIG_CFLAGS)     \
	$(LIBBAALUE_CFLAGS)     \
	-DLOCALEDIR=\"$(localedir)\" -I$(srcdir)/../lib

#food_tracker_LDFLAGS = $(AM_LDFLAGS)

food_tracker_LDADD =  		\
	$(LIBGTK_LIBS)		\
	$(LIBCONFIG_LIBS)   	\
	$(LIBBAALUE_LIBS)      	\
	$(LIBINTL) ../lib/libservice.a
