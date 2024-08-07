#include <iostream>
#include "Sow_thistle.h"
#include "Constants.h"
#include <random>

Sow_thistle::Sow_thistle(World* world, int x, int y)
	: Plant(world, x, y, STRENGTH_PLANT, INITIATIVE_PLANT, NAME_SOW_THISTLE, TYPE_PLANT) {}

Sow_thistle::~Sow_thistle() {}

void Sow_thistle::action() {
	for (int i = 0; i < 3; i++) {
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
}

char Sow_thistle::draw() const {
	return (char)DRAW_SOW_THISTLE;
}

void Sow_thistle::createNew(int x, int y) {
	World* world = this->getWorld();
	Organism* sow_thistle = new Sow_thistle(world, x, y);
	world->addOrganism(sow_thistle);
}