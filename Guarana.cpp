#include <iostream>
#include "Guarana.h"

Guarana::Guarana(World* world, int x, int y)
	: Plant(world, x, y, STRENGTH_PLANT, INITIATIVE_PLANT, NAME_GURANA, TYPE_PLANT) {}

Guarana::~Guarana() {}

int Guarana::collision(Organism* orga, Organism* orgd)
{
	if (orga->getStrength() >= orgd->getStrength()) {
		orgd->isAlive_ = false;
		orga->setStrength(orga->getStrength() + 3);
		this->world_->addEatComment(orga, orgd);
		return 1;
	}
	return 0;
}

char Guarana::draw() const {
	return (char)DRAW_GUARANA;
}

void Guarana::createNew(int x, int y) {
	World* world = this->getWorld();
	Organism* guarana = new Guarana(world, x, y);
	world->addOrganism(guarana);
}
