CC=gcc
TARGET=main

all:
	$(CC) src/BNMO/*.c -o $(TARGET) 

clean:
	rm $(TARGET)