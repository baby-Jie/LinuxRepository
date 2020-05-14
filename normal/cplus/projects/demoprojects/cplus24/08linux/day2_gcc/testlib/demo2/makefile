Target := main
main: main.o libcalc.a
	gcc main.o -o $(Target) -L./includes -lcalc
calc.o: calc.c
	gcc -c calc.c -o calc.o
main.o: main.c
	gcc -c main.c -o main.o 
libcalc.a: calc.o
	ar -rc ./includes/libcalc.a calc.o

clean:
	-rm -rf *.o ./includes/*.a $(Target)
