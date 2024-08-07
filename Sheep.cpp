#include <iostream>
#include "Sheep.h"
#include "World.h"

Sheep::Sheep(World* world, int x, int y)
    : Animal(world, x, y, STRENGTH_SHEEP, INITIATIVE_SHEEP, NAME_SHEEP, TYPE_ANIMAL) {}

Sheep::~Sheep() {}


char Sheep::draw() const {
    return (char)DRAW_SHEEP;
}

void Sheep::createNew(int x, int y) {
	World* world = this->getWorld();
	Organism* sheep = new Sheep(world, x, y);
	world->addOrganism(sheep);
}