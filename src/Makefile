
CC=gcc
DEPS=common.h
OBJS=main.o graphic.o


%.o: %.c $(DEPS)
	$(CC) $< -c


main: $(OBJS) $(DEPS)
	$(CC) -o $@ $^

clean:
	rm *.o
