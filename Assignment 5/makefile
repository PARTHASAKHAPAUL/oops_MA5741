output: main.o linearsystem.o matrix.o Vector.o
	g++ main.o linearsystem.o matrix.o Vector.o -o output

main.o: main.cpp
	g++ -c main.cpp

linearsystem.o: linearsystem.cpp linearsystem.hpp
	g++ -c linearsystem.cpp

matrix.o: matrix.cpp matrix.hpp
	g++ -c matrix.cpp

Vector.o: Vector.cpp Vector.hpp
	g++ -c Vector.cpp

