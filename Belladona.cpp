#include <iostream>
#include "Belladonna.h"

Belladonna::Belladonna(World* world, int x, int y)
	: Plant(world, x, y, STRENGTH_BELLADONNA, INITIATIVE_PLANT, NAME_BELLADONNA, TYPE_PLANT) {}

Belladonna::~Belladonna() {}

int Belladonna::collision(Organism* orga, Organism* orgd)
{
	orga->isAlive_ = false;
	this->world_->addKillComment(orgd, orga);
	return 0;
}

char Belladonna::draw() const {
	return (char)DRAW_BELLADONNA;
}

void Belladonna::createNew(int x, int y) {
	World* world = this->getWorld();
	Organism* belladonna = new Belladonna(world, x, y);
	world->addOrganism(belladonna);
}
