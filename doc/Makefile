SUBDIRS	= gtkdoc
TARGETS	= $(OBJDIR)configctl.1 $(OBJDIR)configctl.html $(OBJDIR)gtkdoc/libSystem.types $(OBJDIR)gtkdoc/tmpl.stamp $(OBJDIR)gtkdoc/sgml.stamp $(OBJDIR)gtkdoc/html.stamp
OBJDIR	=
PREFIX	= /usr/local
DESTDIR	=
RM	= rm -f
LN	= ln -f
MKDIR	= mkdir -m 0755 -p
INSTALL	= install


all: subdirs $(TARGETS)

subdirs:
	@for i in $(SUBDIRS); do (cd "$$i" && \
		if [ -n "$(OBJDIR)" ]; then \
		([ -d "$(OBJDIR)$$i" ] || $(MKDIR) -- "$(OBJDIR)$$i") && \
		$(MAKE) OBJDIR="$(OBJDIR)$$i/"; \
		else $(MAKE); fi) || exit; done

$(OBJDIR)configctl.1: configctl.xml
	./docbook.sh -P "$(PREFIX)" -- "$(OBJDIR)configctl.1"

$(OBJDIR)configctl.html: configctl.css.xml configctl.xml manual.css.xml
	./docbook.sh -P "$(PREFIX)" -- "$(OBJDIR)configctl.html"

$(OBJDIR)gtkdoc/libSystem.types:
	./gtkdoc.sh -P "$(PREFIX)" -- "$(OBJDIR)gtkdoc/libSystem.types"

$(OBJDIR)gtkdoc/tmpl.stamp: $(OBJDIR)gtkdoc/libSystem.types
	./gtkdoc.sh -P "$(PREFIX)" -- "$(OBJDIR)gtkdoc/tmpl.stamp"

$(OBJDIR)gtkdoc/sgml.stamp: $(OBJDIR)gtkdoc/tmpl.stamp
	./gtkdoc.sh -P "$(PREFIX)" -- "$(OBJDIR)gtkdoc/sgml.stamp"

$(OBJDIR)gtkdoc/html.stamp: gtkdoc/libSystem-docs.xml $(OBJDIR)gtkdoc/sgml.stamp $(OBJDIR)gtkdoc/tmpl.stamp
	./gtkdoc.sh -P "$(PREFIX)" -- "$(OBJDIR)gtkdoc/html.stamp"

clean:
	@for i in $(SUBDIRS); do (cd "$$i" && $(MAKE) clean) || exit; done
	$(RM) -- $(configctl.1_OBJS) $(configctl.html_OBJS) $(gtkdoc/libSystem.types_OBJS) $(gtkdoc/tmpl.stamp_OBJS) $(gtkdoc/sgml.stamp_OBJS) $(gtkdoc/html.stamp_OBJS)
	./docbook.sh -c -P "$(PREFIX)" -- "configctl.1"
	./docbook.sh -c -P "$(PREFIX)" -- "configctl.html"
	./gtkdoc.sh -c -P "$(PREFIX)" -- "gtkdoc/libSystem.types"
	./gtkdoc.sh -c -P "$(PREFIX)" -- "gtkdoc/tmpl.stamp"
	./gtkdoc.sh -c -P "$(PREFIX)" -- "gtkdoc/sgml.stamp"
	./gtkdoc.sh -c -P "$(PREFIX)" -- "gtkdoc/html.stamp"

distclean:
	@for i in $(SUBDIRS); do (cd "$$i" && $(MAKE) distclean) || exit; done
	$(RM) -- $(configctl.1_OBJS) $(configctl.html_OBJS) $(gtkdoc/libSystem.types_OBJS) $(gtkdoc/tmpl.stamp_OBJS) $(gtkdoc/sgml.stamp_OBJS) $(gtkdoc/html.stamp_OBJS)
	./docbook.sh -c -P "$(PREFIX)" -- "configctl.1"
	./docbook.sh -c -P "$(PREFIX)" -- "configctl.html"
	./gtkdoc.sh -c -P "$(PREFIX)" -- "gtkdoc/libSystem.types"
	./gtkdoc.sh -c -P "$(PREFIX)" -- "gtkdoc/tmpl.stamp"
	./gtkdoc.sh -c -P "$(PREFIX)" -- "gtkdoc/sgml.stamp"
	./gtkdoc.sh -c -P "$(PREFIX)" -- "gtkdoc/html.stamp"
	$(RM) -- $(TARGETS)

install: $(TARGETS)
	@for i in $(SUBDIRS); do (cd "$$i" && $(MAKE) install) || exit; done
	./docbook.sh -P "$(DESTDIR)$(PREFIX)" -i -- "$(OBJDIR)configctl.1"
	./docbook.sh -P "$(DESTDIR)$(PREFIX)" -i -- "$(OBJDIR)configctl.html"
	./gtkdoc.sh -P "$(DESTDIR)$(PREFIX)" -i -- "$(OBJDIR)gtkdoc/html.stamp"

uninstall:
	@for i in $(SUBDIRS); do (cd "$$i" && $(MAKE) uninstall) || exit; done
	./docbook.sh -P "$(DESTDIR)$(PREFIX)" -u -- "configctl.1"
	./docbook.sh -P "$(DESTDIR)$(PREFIX)" -u -- "configctl.html"
	./gtkdoc.sh -P "$(DESTDIR)$(PREFIX)" -u -- "gtkdoc/html.stamp"

.PHONY: all subdirs clean distclean install uninstall
