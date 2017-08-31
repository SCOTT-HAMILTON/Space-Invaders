#ifndef SHIP_H
#define SHIP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Base.h"

class Ship : public Base
{
public:
	Ship(const sf::Vector2f &pos = {0, 0}, const int radius = 10, const int angle = 0, const sf::Color &color = sf::Color::White);
	void draw(sf::RenderTarget &target);

	//CONTROL FUNC
	void turnRight();
	void turnLeft();
	void boost();
	void shoot();

	static std::vector<Shoot> shoots;

private:
	sf::CircleShape shape;
	static float turnSpeed;
	static float maxSpeed;
	static sf::Vector2f shootSize;
	float speed;

	
};

#endif //SHIP_H