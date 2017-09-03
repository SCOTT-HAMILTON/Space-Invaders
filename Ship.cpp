#include <cmath>

#include "Ship.h"

float Ship::turnSpeed = 180;
float Ship::maxSpeed = 4;
sf::Vector2f Ship::shootSize = {2, 5};
std::vector<Shoot> Ship::shoots;

Ship::Ship(const sf::Vector2f &pos, const int radius, const int angle, const sf::Color &color){
	
	shape = sf::CircleShape(radius, 3);
	shape.setOrigin(shape.getGlobalBounds().width/2, shape.getGlobalBounds().height/2);
	shape.setRotation(angle);
	shape.setPosition(pos);
	shape.setFillColor(sf::Color::Black);
	shape.setOutlineThickness(1);
	shape.setOutlineColor(color);

	left = false;
	right = false;
	boost = false;
	shoot = false;

	speed = 0;

}

void Ship::draw(sf::RenderTarget &target){
	target.draw(shape);
	for (int i = 0; i < shoots.size(); i++){
		target.draw(shoots[i].shape);
	}
	/*
	sf::Vector2f pos = shape.getPosition();
	if (pos.x<0||pos.x>windowSize.x||pos.y<0||pos.y>windowSize.y){
		shape.setPosition(windowSize.x-pos.x, windowSize.y-pos.y);
	}*/
}

void Ship::update(){
	if (left)shape.rotate(turnSpeed/fps);
	if (right)shape.rotate(turnSpeed/fps);
	if (boost){
		if (speed<maxSpeed)speed += 1;
		if (speed>maxSpeed)speed = maxSpeed;
	}
	if (shoot){
		sf::Vector2f vel;
		float rad = (float)M_PI*(float)(shape.getRotation()-90)/(float)180;
		vel.x = std::cos(rad)*6;
		vel.y = std::sin(rad)*6;
		shoots.push_back({sf::RectangleShape(shootSize), vel});
		std::vector<Shoot>::iterator cur_shoot;
		cur_shoot = shoots.end()-1;
		cur_shoot->shape.setOrigin(cur_shoot->shape.getGlobalBounds().width/2, cur_shoot->shape.getGlobalBounds().height/2);
		cur_shoot->shape.setPosition(shape.getPosition());
		cur_shoot->shape.setRotation(shape.getRotation());
		cur_shoot->shape.setFillColor(sf::Color::Yellow);
	}

	float rad = (float)M_PI*(float)(shape.getRotation()-90)/(float)180;
	sf::Vector2f vel;
	vel.x = std::cos(rad)*speed;
	vel.y = std::sin(rad)*speed;
	shape.move(vel);
	for (int i = 0; i < shoots.size(); i++){
		
		shoots[i].shape.move(shoots[i].vel);
		/*
		sf::Vector2f pos = shoots[i].shape.getPosition();
		if (pos.x<0||pos.x>windowSize.x||pos.y<0||pos.y>windowSize.y){
			shoots.erase(shoots.begin()+i);
		}*/
	}
	if (speed>0)speed-=0.2;
	if (speed<0)speed = 0;
}

std::string Ship::toString(){
	return "Ship";
}

void Ship::goleft(){
	left = true;
}

void Ship::noleft(){
	left = false;
}

void Ship::goright(){
	right = true;
}

void Ship::noright(){
	right = false;
}

void Ship::startboost(){
	boost = true;
}

void Ship::stopboost(){
	boost= false;
}

void Ship::startshoot(){
	shoot = true;
}

void Ship::stopshoot(){
	shoot = false;
}