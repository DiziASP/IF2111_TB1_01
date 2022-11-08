CC=gcc
TARGET=main

all:
	$(CC) src/BNMO/*.c src/ADT/Mesin/*.c src/ADT/Array/*.c -o $(TARGET) 

array:
	$(CC) src/ADT/Array/*.c src/Driver_ADT/driverarray.c -o array

queue:
	$(CC) src/ADT/Queue/*.c src/Driver_ADT/driverqueue.c -o queue

mesinkata:
	$(CC) src/ADT/Mesin/*.c src/Driver_ADT/driverwordmachine.c -o mesinkata

mesinkar:
	$(CC) src/ADT/Mesin/*.c src/Driver_ADT/drivercharmachine.c -o mesinkar
	
diner:
	$(CC) src/ADT/Mesin/*.c src/DinerDash/*.c src/DinerDash/ADT_Local/*.c -o diner
	
clean:
	rm $(TARGET)
