#include "Base.h"
#include <cmath>

int Base::fps = 0;
sf::Vector2u Base::windowSize = {0, 0};

void Base::setFps(const int fps){
	Base::fps = fps;
}

void Base::setWindowSize(const sf::Vector2u &windowSize){
	Base::windowSize = windowSize;
}

float Base::dist(const sf::Vector2f& p1, const sf::Vector2f p2){
	return std::sqrt(std::pow(p2.x-p1.x, 2)+std::pow(p2.y-p1.y, 2));
}