#ifndef SHIP_H
#define SHIP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Movable.h"

class Ship : public Movable
{
public:
	Ship(const sf::Vector2f &pos = {0, 0}, const int radius = 10, const int angle = 0, const sf::Color &color = sf::Color::White);
	virtual void draw(sf::RenderTarget &target);
	virtual std::string toString();

	//CONTROL FUNC
	void goleft();
	void noleft();
	void goright();
	void noright();

	void startboost();
	void stopboost();
	void startshoot();
	void stopshoot();

	static std::vector<Shoot> shoots;

protected:
	virtual void update();

private:
	sf::CircleShape shape;
	static float turnSpeed;
	static float maxSpeed;
	static sf::Vector2f shootSize;
	float speed;

	bool left, right, boost, shoot;

	
};

#endif //SHIP_H