all : bin/demo1

bin/demo1 : obj/demo1.o
	g++ -o bin/demo1 obj/demo1.o
	
obj/demo1.o : src/demo1.cpp
	g++ -c -o obj/demo1.o src/demo1.cpp
