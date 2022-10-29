CC=gcc
TARGET=main

all:
	$(CC) src/BNMO/*.c src/ADT/Array/*.c src/ADT/Mesinkarakter/*.c src/ADT/Mesinkata/*.c src/ADT/Queue/*.c -o $(TARGET) 

clean:
	rm $(TARGET)