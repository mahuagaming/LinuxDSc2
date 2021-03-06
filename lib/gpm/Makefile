# Generated automatically from Makefile.in by configure.
#			-*-makefile-*- (gpm/main)
#
# Copyright 1994,1997  rubini@linux.it
# Copyright 1997       dickey@clark.net
# Copyright (C) 1998 Ian Zimmerman <itz@rahul.net>
# Copyright (C) 2001 Nico Schottelius <nico@schottelius.org>
#

SHELL = /bin/sh
srcdir = $(ROOTDIR)/lib/gpm
top_srcdir = $(ROOTDIR)/lib/gpm
top_builddir = .

include Makefile.include

# allow CFLAGS to be overriden from make command line
# ideally one would never have to write this rule again, but the GNU
# makefile standards are at cross-purposes: CFLAGS is reserved for
# user-overridable flags, but it's also all the implicit rule looks at.
# missing ?

SUBDIRS = src #doc contrib

### simple, but effective rules

all: dep do-all

romfs:
		$(ROMFSINST) src/gpm /bin/gpm

dep:
	touch src/$(DEPFILE) # to prevent unecessary warnings
	$(MAKE) -C src dep

check: all

uninstall:	do-uninstall

clean: do-clean

Makefile: #$(srcdir)/Makefile.in config.status
#	./config.status

config.status:	$(srcdir)/configure
	if [ -f config.status ]; then $(SHELL) config.status --recheck; \
	else ./configure; fi

### INSTALL

install:	check installdirs do-install

install-strip:
	$(MAKE) INSTALL_PROGRAM='$(INSTALL_PROGRAM) $(STRIP)' install

installdirs:
	$(MKDIR) $(libdir) $(bindir) $(sbindir) $(includedir) $(sysconfdir); \
	if test "x" != "x" ; then \
		$(MKDIR) $(lispdir) ; \
	fi

### GENERIC

# do-all goes to all subdirectories and does all
do-%:
	@target=`echo $@ | $(SED) -e 's/^do-//'`; \
	for i in $(SUBDIRS) ; do \
		if test -f ./$$i/Makefile ; then \
			$(MAKE) -C ./$$i $${target} || exit 1 ;\
		else \
			true; \
		fi; \
done


# Configure & unconfigure

# Maintainer portion, use at your own risk

barf:
	@echo 'This command is intended for maintainers to use; it'
	@echo 'deletes files that may need special tools to rebuild.'
	@echo 'If you want to continue, please press return.'
	@read -p "Hit Ctrl+C to abort."


# who / what does need tags
TAGS:	$(SRCS) $(HDRS) src/prog/gpm-root.y do-TAGS
	cd $(srcdir) && $(ETAGS) -o TAGS $(SRCS) $(HDRS) src/prog/gpm-root.y

# Do the the next release

# 1. Cleanup the tree, remove all generated files and so on
distclean: barf clean do-clean do-distclean
	rm -f config.log config.status config.cache Makefile Makefile.include
	rm -f configure
	rm -rf gpm-$(release) gpm-$(release).tar.bz2 gpm-$(release).tar.gz
	rm -f src/$(DEPFILE)

# STOPPPED HERE
gpm-$(release): distclean do-distclean
	mkdir -p gpm-$(release)
	for  file in $(srcdir)/*; do \
		if [ "`basename $$file`" != "$@" ]; then \
			cp $$file gpm-$(release) -r; \
		fi; \
	done

# 2. configure headers, produce new configure script
distconf: configure.in aclocal.m4
	autoheader && autoconf

# make this clean...
gpm-$(release).tar: gpm-$(release)
	$(TAR) cf - gpm-$(release) > $@

gpm-$(release).tar.gz:  gpm-$(release).tar
	gzip -9 -c gpm-$(release).tar > $@

gpm-$(release).tar.bz2:  gpm-$(release).tar
	bzip2 -k gpm-$(release).tar

# 3. Put package together into .tar.gz and .tar.bz2
dist: distclean distconf gpm-$(release).tar.bz2 gpm-$(release).tar.gz
	rm gpm-$(release).tar
	rm -r gpm-$(release)

