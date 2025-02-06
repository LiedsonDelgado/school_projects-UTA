CC = gcc

CFLAGS = -Wall
TARGET = main

OBJS = main.o Func.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

main.o: main.c Def_Func.h
	$(CC) $(CFLAGS) -c main.c

Func.o: Func.c Def_Func.h
	$(CC) $(CFLAGS) -c Func.c

clean:
	rm -f $(OBJECTS) $(TARGET)
