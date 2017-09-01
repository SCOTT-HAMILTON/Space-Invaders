

LIBS = -lsfml-graphics-d -lsfml-window-d -lsfml-system-d

TARGET = 'Space Invaders'

all: compile
	g++ -g main.o Ship.o Base.o Cible.o -o $(TARGET) $(LIBS);
	rm main.o;
	rm Ship.o;
	rm Base.o;
	rm Cible.o;

compile: main.cpp Ship.cpp
	g++ -c main.cpp -std=c++11;
	g++ -c Ship.cpp -std=c++11;
	g++ -c Base.cpp -std=c++11;
	g++ -c Cible.cpp -std=c++11;