CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Os `pkg-config --cflags vte-2.91`
LIBS = `pkg-config --libs vte-2.91`

PREFIX = /usr/local
DATADIR = $(PREFIX)/share

catty: catty.c
	${CC} -o catty catty.c ${CFLAGS} ${LIBS}

install: catty
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f catty $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/catty
	mkdir -p $(DESTDIR)$(DATADIR)
	cp -f catty.desktop $(DESTDIR)$(DATADIR)/catty.desktop
	chmod 644 $(DESTDIR)$(DATADIR)/catty.desktop


clean:
	rm -f catty
