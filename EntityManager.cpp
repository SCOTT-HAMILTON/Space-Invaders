#include "EntityManager.h"

EntityManager::EntityManager(const std::vector<std::unique_ptr<Entity>> &entitys){
	for (int i = 0; i < entitys.size(); i++){
		this->entitys.push_back(std::unique_ptr<Entity>(entitys[i].get()));
	}
}

void EntityManager::addEntity(const std::unique_ptr<Entity> &entity){
	entitys.push_back(std::unique_ptr<Entity>(entity.get()));
}

void EntityManager::manage(){
	sf::Clock c;
	sf::Time t;
	t = c.gelElapsedTime();
	while (continuer){
		if (c.gelElapsedTime().asMilliseconds()-t.asMilliseconds()>)
	}
}