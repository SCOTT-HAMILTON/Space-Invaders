

LIBS = -lsfml-graphics-d -lsfml-window-d -lsfml-system-d

TARGET = 'Space Invaders'

all: compile
	g++ -g main.o Entity.o Movable.o Ship.o Cible.o EntityManager.o -o $(TARGET) $(LIBS);
	rm main.o;
	rm Entity.o;
	rm Movable.o;
	rm Ship.o;
	rm Cible.o;
	rm EntityManager.o;

compile: main.cpp Ship.cpp
	g++ -c main.cpp -std=c++11;
	g++ -c Entity.cpp -std=c++11;
	g++ -c Movable.cpp -std=c++11;
	g++ -c Ship.cpp -std=c++11;
	g++ -c Cible.cpp -std=c++11;
	g++ -c EntityManager.cpp -std=c++11;