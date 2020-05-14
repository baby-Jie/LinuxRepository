Target := main

$(Target): calc.o main.o
	$(CC) main.o calc.o -o $(Target)
calc.o: calc.c
	gcc -c calc.c -o calc.o
main.o: main.c
	gcc -c main.c -o main.o
clean:
	-rm -rf *.o $(Target)
