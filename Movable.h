#ifndef MOVABLE_H

#define MOVABLE_H

#ifndef M_PI
#define M_PI 3.14159265359 
#endif

#include <SFML/Graphics.hpp>

#include "Entity.h"

struct Shoot2{
	sf::RectangleShape shape;
	sf::Vector2f vel;
};

typedef Shoot2 Shoot;


class Movable : public Entity
{
public:
	virtual void update();
	virtual std::string toString();
};

#endif //MOVABLE_H