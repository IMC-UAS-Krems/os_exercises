CC = gcc
CCFLAGS = -Wall

all: mutex_example semaphore_example pthreads_example

pthreads_example: pthreads_example.o
	$(CC) $(CCFLAGS) -o pthreads_example pthreads_example.o -pthread

mutex_example: mutex_example.o
	$(CC) $(CCFLAGS) -o mutex_example mutex_example.o -pthread

semaphore_example: semaphore_example.o
	$(CC) $(CCFLAGS) -o semaphore_example semaphore_example.o -pthread

clean:
	- rm *.o
	- rm mutex_example
	- rm semaphore_example
	- rm pthreads_example
