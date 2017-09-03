#ifndef ENTITY_H

#define ENTITY_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

class Entity{
public:
	virtual void draw(sf::RenderTarget &target);

	static int fps; 
	static sf::Vector2u windowSize;
	static void setFps(const int fps);
	static void setWindowSize(const sf::Vector2u &windowSize);

	static float dist(const sf::Vector2f& p1, const sf::Vector2f p2);
	virtual std::string toString(); 
};

#endif //ENTITY_H