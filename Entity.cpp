#include "Entity.h"
#include <cmath>

int Entity::fps = 0;
sf::Vector2u Entity::windowSize = {0, 0};

void Entity::setFps(const int fps){
	Entity::fps = fps;
}

void Entity::setWindowSize(const sf::Vector2u &windowSize){
	Entity::windowSize = windowSize;
}

float Entity::dist(const sf::Vector2f& p1, const sf::Vector2f p2){
	return std::sqrt(std::pow(p2.x-p1.x, 2)+std::pow(p2.y-p1.y, 2));
}

void Entity::draw(sf::RenderTarget &target){}

std::string Entity::toString(){
	return "Entity";
}