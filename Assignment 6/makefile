output: main_rk4.o rk4.o AbstractOdeSolver.o
	g++ main_rk4.o rk4.o AbstractOdeSolver.o -o output

main_rk4.o: main_rk4.cpp AbstractOdeSolver.hpp rk4.hpp
	g++ -c main_rk4.cpp

rk4.o: rk4.cpp rk4.hpp AbstractOdeSolver.hpp
	g++ -c rk4.cpp

AbstractOdeSolver.o: AbstractOdeSolver.cpp AbstractOdeSolver.hpp
	g++ -c AbstractOdeSolver.cpp
