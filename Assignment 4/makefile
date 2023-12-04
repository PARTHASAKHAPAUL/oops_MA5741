output: main.o phd.o grad.o student.o
	g++ main.o phd.o grad.o student.o -o output

main.o: main.cpp
	g++ -c main.cpp

phd.o: phd.cpp phd.hpp
	g++ -c phd.cpp

grad.o: grad.cpp grad.hpp
	g++ -c grad.cpp

student.o: student.cpp student.hpp
	g++ -c student.cpp

