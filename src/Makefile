
CC=gcc
DEPS=tgl.h
OBJS=main.o


%.o: %.c $(DEPS)
	$(CC) $< -c


main: $(OBJS) $(DEPS)
	$(CC) -o $@ $^

clean:
	rm *.o
