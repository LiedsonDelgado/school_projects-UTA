CC = gcc

CFLAGS = -Wall

OBJECTS = cinema.o

TARGET = cinema

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

main.o: cinema.c
	$(CC) $(CFLAGS) -c cinema.c
