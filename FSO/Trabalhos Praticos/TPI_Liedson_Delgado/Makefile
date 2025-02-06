CC = gcc

CFLAGS = -Wall
TARGET = main

OBJS = main.o funcoes.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

main.o: main.c header.h
	$(CC) $(CFLAGS) -c main.c

funcoes.o: funcoes.c header.h
	$(CC) $(CFLAGS) -c funcoes.c

clean:
	rm -f $(OBJS) $(TARGET)
