all = main
main: main.cpp Cow.o Farm.o Farm.h Cow.h
	g++ -o main main.cpp Cow.o Farm.o Farm.h Cow.h
Cow.o: Cow.h Cow.cpp
	g++ -c Cow.h Cow.cpp
Farm.o: Farm.cpp Farm.h Cow.o Cow.h
	g++ -c Farm.cpp Farm.h Cow.o Cow.h