#include <cstdlib>
#include "Plant.h"
#include "World.h"
#include "Constants.h"
#include <random>

Plant::Plant(World* world, int x, int y, int strength, int initiative, string name, char type)
    : Organism(world, x, y, strength, initiative, name, TYPE_PLANT)
{
}

Plant::~Plant()
{
}

void Plant::action()
{
	int newX = x_;
	int newY = y_;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, SPREAD_RATE);
	int random = dis(gen);
	switch (random) {
	case 0:
		newX += 1;
		break;
	case 1:
		newY += 1;
		break;
	case 2:
		newX -= 1;
		break;
	case 3:
		newY -= 1;
		break;
	}

	if (newX >= 0 && newX < world_->getWidth() && newY >= 0 && newY < world_->getHeight()) {
		Organism* org = world_->getOrganism(newX, newY);
		if (org == nullptr) {
			this->createNew(newX, newY);
		}
	}
}

int Plant::collision(Organism* orga, Organism* orgd) {
	if (orga->getStrength() >= orgd->getStrength()) {
		orgd->isAlive_ = false;
		this->world_->addEatComment(orga, orgd);
		return 1;
	}
	return 0;
}