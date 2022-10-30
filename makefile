CC=gcc
TARGET=main

all:
	$(CC) src/BNMO/*.c src/ADT/Mesin/*.c -o $(TARGET) 

clean:
	rm $(TARGET)