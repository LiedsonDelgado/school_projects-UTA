CC = gcc

CFLAGS = -Wall
TARGET = cinema

OBJS = cinema.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

cinema.o: cinema.c
	$(CC) $(CFLAGS) -c cinema.c

clean:
	rm -f $(OBJS) $(TARGET)
