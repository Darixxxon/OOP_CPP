#include "Commentator.h"
#include "Animal.h"
#include "World.h"
#include <iostream>
#include <random>

using namespace std;

Animal::Animal(World* world, int x, int y, int strength, int initiative, string name, char type)
	: Organism(world, x, y, strength, initiative, name, TYPE_ANIMAL) {}

Animal::~Animal(){}

void Animal::action() {
	int newX = x_;
	int newY = y_;
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

	if (newX >= 0 && newX < world_->getWidth() && newY >= 0 && newY < world_->getHeight()) {
		Organism* org = world_->getOrganism(newX, newY);
		if (org == nullptr) {
			x_ = newX;
			y_ = newY;
		}
		else{
			if (org->collision(this, org)) {
				x_ = newX;
				y_ = newY;
			}
		}
	}
}

int Animal::collision(Organism* orga, Organism* orgd) {
	if (orga->getName() == orgd->getName()) {
		this->detectFree(this->getX(), this->getY());
	}
	else {
		if (orga->getStrength() >= orgd->getStrength()) {
			orgd->isAlive_ = false;
			this->world_->addKillComment(orga, orgd);
			return 1;
		}
	}
	return 0;
}

void Animal::detectFree(int x, int y)
{
	int f = 0;
	while(f!=4)
	{
		f = 0;
		if (world_->getOrganism(x + 1, y) != nullptr || x + 1 >= world_->getWidth())
		{
			f += 1;
			if (world_->getOrganism(x - 1, y) != nullptr || x - 1 < 0)
			{
				f += 1;
				if(world_->getOrganism(x, y + 1) != nullptr || y + 1 >= world_->getHeight())
				{
					f += 1;
					if (world_->getOrganism(x, y - 1) != nullptr || y - 1 < 0)
					{
						f += 1;
					}
				}
			}
		}
		int newX = x;
		int newY = y;
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
		World* world_ = this->getWorld();
		if (newX >= 0 && newX < world_->getWidth() && newY >= 0 && newY < world_->getHeight()) {
			Organism* org = world_->getOrganism(newX, newY);
			if (org == nullptr) {
				this->createNew(newX, newY);
				return;
			}
		}
	}
}


