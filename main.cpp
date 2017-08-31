#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "Ship.h"
#include "Base.h"
#include "Cible.h"

const int fps = 60;

const int width = 640;
const int height = 480;

const int nb_asteroids = 10;

int main (int argc, char *argv[]){

	Base::setFps(fps);
	srand(time(0));

	sf::RenderWindow fenetre(sf::VideoMode(width, height), "Space Invaders");
	Base::setWindowSize(fenetre.getSize());
	fenetre.setFramerateLimit(fps);
	sf::Event event;


	//MY SHIP!
	Ship myship(sf::Vector2f(width/2, height/2), 15);

	//ASTEROIDS
	std::vector<Cible> asteroids;
	for (int i = 0; i < nb_asteroids; i++){
		sf::Vector2f pos;
		pos.x = rand()%width;
		pos.y = rand()%height;
		int radius = rand()%10+5;
		asteroids.push_back(Cible(pos, radius));
	}

	//EVENT BOOL
	bool left = false, right = false, boost = false;
	bool shoot = false;

	//PLAYER DATA
	int score = 0;

	//TEXT DRAWED ON THE WINDOW
	sf::Font font;
	if (!font.loadFromFile("NotoSansCJK-Light.ttc")){
		std::cout << "Can't open font : NotoSansCJK-Light.ttc" << std::endl;
		return 1;
	}
	sf::Text textscore;
	textscore.setFont(font);
	
	textscore.setCharacterSize(15);
	textscore.setFillColor(sf::Color(13, 83, 255));
	textscore.setString(std::string("score : "+std::to_string(score)));
	textscore.setPosition(10, 10);

	//MAIN WHILE LOOP
	while (fenetre.isOpen() && asteroids.size()>0){
		while (fenetre.pollEvent(event)){
			if (event.type == sf::Event::Closed)fenetre.close();

			else if (event.type == sf::Event::KeyPressed){
				if (event.key.code == sf::Keyboard::Left)left = true;
				else if (event.key.code == sf::Keyboard::Right)right = true;
				else if (event.key.code == sf::Keyboard::Up)boost = true;
				else if (event.key.code == sf::Keyboard::Space)shoot = true;
			}

			else if (event.type == sf::Event::KeyReleased){
				if (event.key.code == sf::Keyboard::Left)left = false;
				else if (event.key.code == sf::Keyboard::Right)right = false;
				else if (event.key.code == sf::Keyboard::Up)boost = false;
				else if (event.key.code == sf::Keyboard::Space)shoot = false;
			}
		}

		if (left){
			myship.turnLeft();
		}
		if (right){
			myship.turnRight();
		}
		if (boost){
			myship.boost();
		}
		if (shoot){
			myship.shoot();
		}

		fenetre.clear();

		//DRAW TIME!
		myship.draw(fenetre);
		for (int i = asteroids.size()-1; i >= 0; i--){
			asteroids[i].draw(fenetre);
			bool continuer = true;
			for (int j = 0; j < Ship::shoots.size(); j++){
				if (asteroids[i].touchShoot(Ship::shoots[j])){
					score++;
					textscore.setString(std::string("score : "+std::to_string(score)));
					int baseradius = asteroids[i].getbaseradius();
					asteroids.erase(asteroids.begin()+i);
					if ((float)baseradius/2>2 && rand()%5>2){
						sf::Vector2f pos;
						pos.x = rand()%width;
						pos.y = rand()%height;
						asteroids.push_back(Cible(pos, baseradius/2));
						pos.x += rand()%6-3;
						pos.y += rand()%6-3;
						asteroids.push_back(Cible(pos, baseradius/2));
					}
					continuer = false;
					break;
				}
			}
			if (continuer){
				if (!asteroids[i].isMoving()){
					sf::Vector2f pos;
					pos.x = rand()%width;
					pos.y = rand()%height;
					asteroids[i].restart(pos);	
				}
			}
		}

		fenetre.draw(textscore);

		fenetre.display();
	}

	sf::Text textwin;
	textwin.setFont(font);
	
	textwin.setCharacterSize(30);
	textwin.setFillColor(sf::Color::White);
	textwin.setString(std::string("You win !"));
	textwin.setOrigin(textwin.getGlobalBounds().width/2, textwin.getGlobalBounds().height/2);
	textwin.setPosition(width/2, height/2);

	while (fenetre.isOpen()){
		while (fenetre.pollEvent(event)){
			if (event.type == sf::Event::Closed)fenetre.close();
		}

		fenetre.clear();
		fenetre.draw(textwin);
		fenetre.display();
	}
}