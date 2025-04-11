CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm

OBJS = perceptron.o vectorio.o settings.o

all: perceptron

perceptron: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) perceptron
