demo2: demo2.cpp complex.o
	g++ demo2.cpp complex.o -o demo2
demo1: demo1.cpp complex.o
	g++ demo1.cpp complex.o -o demo1
complex.o: complex.cpp
	g++ -c complex.cpp -o complex.o
clean:
	-rm -rf *.o demo1 a.out demo2

