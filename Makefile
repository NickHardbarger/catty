CC = cc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Os
LDFLAGS = -lvte-2.91

catty: catty.c
	${CC} -o catty catty.c ${CFLAGS} ${LDFLAGS}

install: catty
	rm /home/nickh/nix/system/bin/catty
	mv catty /home/nickh/nix/system/bin

clean:
	rm -f catty
