#include <cstdlib>
#include <ctime>
#include <cmath>

#include "Cible.h"

float Cible::speed = 1.5;
int Cible::id = 1;

Cible::Cible(const sf::Vector2f &pos, const int &baseradius){
	myid = id;
	id++;
	this->baseradius = baseradius;
	srand(time(0)*(myid*myid));
	int nb_point = rand()%12+3;  
	shape = new sf::ConvexShape(nb_point);
	float marge = this->baseradius*0.5f;
	distmoyenne = 0;
	for (int i = 0; i < nb_point; i++){
		float d = rand()%(int)(baseradius+marge-(baseradius-marge))+marge;
		distmoyenne += d;
		sf::Vector2f tmp;
		float rad = (float)M_PI*(float)(i*360/nb_point)/(float)180;
		tmp.x = std::cos(rad)*d;
		tmp.y = std::sin(rad)*d;
		shape->setPoint(i, tmp);
	}
	distmoyenne /= nb_point;
	shape->setOrigin(shape->getGlobalBounds().width/2, shape->getGlobalBounds().height/2);
	shape->setPosition(pos);
	shape->setFillColor(sf::Color::Black);
	shape->setOutlineThickness(1);
	shape->setOutlineColor(sf::Color::White);

	int angle = rand()%360;
	float rad = (float)M_PI*(float)(angle)/(float)180;
	vec.x = std::cos(rad)*speed;
	vec.y = std::sin(rad)*speed;

	move = true;
}

void Cible::draw(sf::RenderTarget &target){
	target.draw((*(shape)));
}

void Cible::update(){
	if (move){
		shape->move(vec);
		
		sf::Vector2f pos = shape->getPosition();
		
		if (pos.x<0||pos.x>windowSize.x||pos.y<0||pos.y>windowSize.y){
			move = false;
		}
	}
}

std::string Cible::toString(){
	return "Cible";
}

bool Cible::isMoving(){
	return move;
}

void Cible::restart(const sf::Vector2f &pos, const int &baseradius){
	this->baseradius = baseradius;
	srand(time(0)*(myid*myid));
	int nb_point = rand()%12+3;  
	shape = new sf::ConvexShape(nb_point);
	float marge = this->baseradius*0.5f;
	distmoyenne = 0;
	for (int i = 0; i < nb_point; i++){
		float d = rand()%(int)(baseradius+marge-(baseradius-marge))+marge;
		distmoyenne += d;
		sf::Vector2f tmp;
		float rad = (float)M_PI*(float)(i*360/nb_point)/(float)180;
		tmp.x = std::cos(rad)*d;
		tmp.y = std::sin(rad)*d;
		shape->setPoint(i, tmp);
	}
	distmoyenne /= nb_point;
	shape->setOrigin(shape->getGlobalBounds().width/2, shape->getGlobalBounds().height/2);
	shape->setPosition(pos);
	shape->setFillColor(sf::Color::Black);
	shape->setOutlineThickness(1);
	shape->setOutlineColor(sf::Color::White);

	int angle = rand()%360;
	float rad = (float)M_PI*(float)(angle)/(float)180;
	vec.x = std::cos(rad)*speed;
	vec.y = std::sin(rad)*speed;

	move = true;
}

int Cible::getbaseradius(){
	return baseradius;
}

bool Cible::touchShoot(const Shoot &shoot){
	float d = dist(shoot.shape.getPosition(), shape->getPosition());
	if (d<distmoyenne)return true;
	return false;
}