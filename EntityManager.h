#ifndef ENTITYMANAGER_H

#define ENTITYMANAGER_H

#include <iostream>
#include <memory>

#include "Entity.h"
#include "Movable.h"

class EntityManager : public Entity{
public:
	EntityManager(const std::vector<std::unique_ptr<Entity>> &entitys);
	void manage();
	void addEntity(const std::unique_ptr<Entity> &entity);

private:
	std::vector<std::unique_ptr<Entity>> entitys;
	bool continuer;

};

#endif //ENTITYMANAGER_H