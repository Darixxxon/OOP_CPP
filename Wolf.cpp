#include <iostream>
#include "Wolf.h"
#include "World.h"

Wolf::Wolf(World* world, int x, int y)
	: Animal(world, x, y, STRENGTH_WOLF, INITIATIVE_WOLF, NAME_WOLF, TYPE_ANIMAL) {}

Wolf::~Wolf() {}

char Wolf::draw() const {
	return (char)DRAW_WOLF;
}

void Wolf::createNew(int x, int y) {
	World* world = this->getWorld();
	Organism* wolf = new Wolf(world, x, y);
	world->addOrganism(wolf);
}