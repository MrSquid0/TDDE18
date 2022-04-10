all : bin/tiempo

bin/tiempo : obj/main.o obj/tiempo.o obj/tiempo.h
	@echo Creando el ejecutable bin/tiempo...
	g++ -o bin/tiempo obj/main.cpp obj/tiempo.cpp obj/tiempo.h

obj/main.o : src/main.cpp include/tiempo.h
	@echo Creando el modulo objeto obj/main.cpp...
	g++ -c -I./include -o obj/main.o src/main.cpp

obj/tiempo.o : src/tiempo.cpp include/tiempo.h
	@echo Creando el modulo objeto obj/tiempo.o
	g++ -c -I./include o obj/tiempo.o src/tiempo.cpp
