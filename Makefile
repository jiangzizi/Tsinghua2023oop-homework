all = main
main: main.cpp manager.h chef.h  manager.o chef.o
	g++ -o main main.cpp manager.h chef.h  manager.o chef.o
manager.o: manager.cpp manager.h chef.o chef.h
	g++ -c manager.cpp manager.h chef.o chef.h
chef.o: chef.h chef.cpp
	g++ -c chef.cpp chef.h