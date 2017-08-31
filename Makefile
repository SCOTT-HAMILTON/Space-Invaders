

LIBS = -lsfml-graphics-d -lsfml-window-d -lsfml-system-d

TARGET = 'Space Invaders'

all: compile
	g++ -g main.o Ship.o Base.o Cible.o -o $(TARGET) $(LIBS);
	rm main.o;
	rm Ship.o;
	rm Base.o;
	rm Cible.o;

compile: main.cpp Ship.cpp
	g++ -c main.cpp -std=c++11 -lgcc_s -lgcc;
	g++ -c Ship.cpp -std=c++11 -lgcc_s -lgcc;
	g++ -c Base.cpp -std=c++11 -lgcc_s -lgcc;
	g++ -c Cible.cpp -std=c++11 -lgcc_s -lgcc;