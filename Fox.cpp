#include <iostream>
#include "Fox.h"
#include <random>

Fox::Fox(World* world, int x, int y)
    : Animal(world, x, y, STRENGTH_FOX, INITIATIVE_FOX, NAME_FOX, TYPE_ANIMAL) {}

Fox::~Fox() {}

void Fox::action() {
	int newX = x_;
	int newY = y_;
	while (true) {
		newX = x_;
		newY = y_;
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(0, 3);
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
		Organism* org = world_->getOrganism(newX, newY);
		if (org == nullptr)
		{
			break;
		}
		else if (org->getStrength() <= this->strength_)
		{
			break;
		}
		int f = 0;
		if ((world_->getOrganism(x_ + 1, y_) != nullptr && (world_->getOrganism(x_ + 1, y_)->getStrength() > this->strength_) ) || x_ + 1 >= world_->getWidth())
		{
			f += 1;
			if ((world_->getOrganism(x_ - 1, y_) != nullptr && (world_->getOrganism(x_ - 1, y_)->getStrength() > this->strength_) ) || x_ - 1 < 0)
			{
				f += 1;
				if ((world_->getOrganism(x_, y_ + 1) != nullptr && (world_->getOrganism(x_, y_ + 1)->getStrength() > this->strength_) ) || y_ + 1 >= world_->getHeight())
				{
					f += 1;
					if ((world_->getOrganism(x_, y_ - 1) != nullptr && (world_->getOrganism(x_, y_ - 1)->getStrength() > this->strength_) || y_ - 1 < 0))
					{
						f += 1;
					}
				}
			}
		}
	}

	if (newX >= 0 && newX < world_->getWidth() && newY >= 0 && newY < world_->getHeight()) {
		Organism* org = world_->getOrganism(newX, newY);
		if (org == nullptr) {
			x_ = newX;
			y_ = newY;
		}
		else {
			if (org->collision(this, org)) {
				x_ = newX;
				y_ = newY;
			}
		}
	}
}

char Fox::draw() const {
    return (char)DRAW_FOX;
}

void Fox::createNew(int x, int y) {
	World* world = this->getWorld();
	Organism* fox = new Fox(world, x, y);
	world->addOrganism(fox);
}