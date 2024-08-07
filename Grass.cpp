#include <iostream>
#include "Grass.h"

Grass::Grass(World* world, int x, int y)
	: Plant(world, x, y, STRENGTH_PLANT, INITIATIVE_PLANT, NAME_GRASS, TYPE_PLANT) {}

Grass::~Grass() {}

char Grass::draw() const {
	return (char)DRAW_GRASS;
}

void Grass::createNew(int x, int y) {
	World* world = this->getWorld();
	Organism* grass = new Grass(world, x, y);
	world->addOrganism(grass);
}