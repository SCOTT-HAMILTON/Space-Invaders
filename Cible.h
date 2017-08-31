#ifndef CIBLE_H

#define CIBLE_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Base.h"

class Cible : public Base
{
public:
	Cible(const sf::Vector2f &pos = {0, 0}, const int &baseradius = 10);
	void draw(sf::RenderTarget &target);
	bool isMoving();
	void restart(const sf::Vector2f &pos = {0, 0}, const int &baseradius = 10);
	int getbaseradius();
	bool touchShoot(const Shoot &shoot);

private:
	sf::ConvexShape *shape;
	sf::Vector2f vec;
	static float speed;
	bool move;
	int myid;
	int baseradius;
	int distmoyenne;

	static int id;
};

#endif //CIBLE_H