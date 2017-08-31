#ifndef BASE_H

#define BASE_H

#include <SFML/Graphics.hpp>

struct Shoot2{
	sf::RectangleShape shape;
	sf::Vector2f vel;
};

typedef Shoot2 Shoot;


class Base{
public:
	static int fps; 
	static sf::Vector2u windowSize;
	static void setFps(const int fps);
	static void setWindowSize(const sf::Vector2u &windowSize);

	static float dist(const sf::Vector2f& p1, const sf::Vector2f p2);
};

#endif //BASE_H