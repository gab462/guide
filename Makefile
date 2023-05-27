OBJS = app.o arena.o input.o entity.o scene.o component.o list.o
LIB = libguide.a

$(LIB): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	c99 -Wall -Wextra -Wshadow -pedantic -o $@ -c $<

fmt: $(wildcard *.c) app.h
	VERSION_CONTROL=none indent -nut $^

clean: $(LIB) $(OBJS)
	rm $^
