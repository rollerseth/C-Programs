CFLAGS = -std=gnu99 `pkg-config --cflags gtk+-3.0` 
LDLIBS = -lm `pkg-config --libs gtk+-3.0`

all : demo grid

graphics.o : graphics.c graphics.h
	gcc $(CFLAGS) -c graphics.c

demo : demo.c graphics.o graphics.h
	gcc $(CFLAGS) demo.c graphics.o -o demo $(LDLIBS)

grid : grid.c graphics.o graphics.h
	gcc $(CFLAGS) grid.c graphics.o -o grid $(LDLIBS)

diamonds : diamonds.c graphics.o graphics.h
	gcc $(CFLAGS) diamonds.c graphics.o -o diamonds $(LDLIBS)

rw : rw.c graphics.o graphics.h
	gcc $(CFLAGS) rw.c graphics.o -o rw $(LDLIBS)

