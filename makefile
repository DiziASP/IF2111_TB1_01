CC=gcc
TARGET=BNMO

all:
	$(CC) src/BNMO/*.c src/ADT/Mesin/*.c src/ADT/Array/*.c src/ADT/Queue/*.c src/ADT/Stack/*.c src/ADT/Set/*.c src/ADT/Map/*.c src/ADT/LinkedList/*.c src/RNG/*.c src/UserCreated/*.c src/DinerDash/*.c src/DinerDash/ADT_Local/*.c src/Hangman/*.c -o $(TARGET) 

array:
	$(CC) src/ADT/Array/*.c src/Driver_ADT/driverarray.c -o array

queue:
	$(CC) src/ADT/Queue/*.c src/Driver_ADT/driverqueue.c -o queue

mesinkata:
	$(CC) src/ADT/Mesin2/*.c src/Driver_ADT/drivermesinkata.c -o mesinkata

mesinkar:
	$(CC) src/ADT/Mesin2/*.c src/Driver_ADT/drivermesinkar.c -o mesinkar

linkedlist:
	$(CC) src/ADT/LinkedList/*.c src/Driver_ADT/driverLL.c -o linkedlist

set:
	$(CC) src/ADT/Set/*.c src/Driver_ADT/driverset.c -o set

map:
	$(CC) src/ADT/Map/*.c src/Driver_ADT/drivermap.c -o map

diner:
	$(CC) src/ADT/Mesin/*.c src/DinerDash/*.c src/DinerDash/ADT_Local/*.c -o diner

usercreated:
	$(CC) src/UserCreated/*.c src/ADT/Array/*.c -o usercreated

hangman:
	$(CC) src/Hangman/*.c src/ADT/Mesin/*.c src/ADT/Array/*.c src/ADT/Set/*.c -o hangman
	
clean:
	rm $(TARGET)
