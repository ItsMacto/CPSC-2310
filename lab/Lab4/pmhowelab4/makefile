CC = gcc
CFLAGS = -Wall -g
TARGET = matrix_program
OBJS = driver.o functions.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: driver.c functions.h
	$(CC) $(CFLAGS) -c driver.c

functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c

run:
	./$(TARGET) input.txt

clean:
	rm -f *.o $(TARGET)