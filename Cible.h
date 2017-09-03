#ifndef CIBLE_H

#define CIBLE_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Movable.h"

class Cible : public Movable
{
public:
	Cible(const sf::Vector2f &pos = {0, 0}, const int &baseradius = 10);
	virtual void draw(sf::RenderTarget &target);
	virtual std::string toString();

	bool isMoving();
	void restart(const sf::Vector2f &pos = {0, 0}, const int &baseradius = 10);
	int getbaseradius();
	bool touchShoot(const Shoot &shoot);

protected:
	virtual void update();

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