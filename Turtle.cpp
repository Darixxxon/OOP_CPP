#include <iostream>
#include "Turtle.h"
#include <iostream>
#include <random>

Turtle::Turtle(World* world, int x, int y)
    : Animal(world, x, y, STRENGTH_TURTLE, INITIATIVE_TURTLE, NAME_TURTLE, TYPE_ANIMAL) {}

Turtle::~Turtle() {}

void Turtle::action() {

		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(0, 3);
		int rand = dis(gen);
		if (rand == 3)
		{
			int random = dis(gen);
			int newX = x_;
			int newY = y_;
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
}

int Turtle::collision(Organism* orga, Organism* orgd)
{
	if (orga->getName() == orgd->getName()) {
		this->detectFree(this->getX(), this->getY());
	}
	else {
		if (orga->getStrength() < 5)
		{
			return 0;
		}
		else if (orga->getStrength() >= orgd->getStrength()) {
			orgd->isAlive_ = false;
			this->world_->addKillComment(orga, orgd);
			return 1;
		}
		return 0;
	}
}

char Turtle::draw() const {
    return (char)DRAW_TURTLE;
}

void Turtle::createNew(int x, int y) {
	World* world = this->getWorld();
	Organism* turtle = new Turtle(world, x, y);
	world->addOrganism(turtle);
}