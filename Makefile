CC = cc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Os `pkg-config --cflags vte-2.91`
LIBS = `pkg-config --libs vte-2.91`

catty: catty.c
	${CC} -o catty catty.c ${CFLAGS} ${LIBS}

install: catty
	rm /home/nickh/nix/system/bin/catty
	mv catty /home/nickh/nix/system/bin

clean:
	rm -f catty
