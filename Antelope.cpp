#include <iostream>
#include "Antelope.h"
#include "World.h"
#include <random>

Antelope::Antelope(World* world, int x, int y)
	: Animal(world, x, y, STRENGTH_ANTELOPE, INITIATIVE_ANTELOPE, NAME_ANTELOPE, TYPE_ANIMAL) {}

Antelope::~Antelope() {}

void Antelope::action() {
	int newX = x_;
	int newY = y_;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 3);
	int random = dis(gen);
	switch (random) {
	case 0:
		newX += 2;
		break;
	case 1:
		newY += 2;
		break;
	case 2:
		newX -= 2;
		break;
	case 3:
		newY -= 2;
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

int Antelope::collision(Organism* orga, Organism* orgd)
{
	if (orga->getName() == orgd->getName()) {
		this->detectFree(this->getX(), this->getY());
	}
	else {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(0, 1);
		int random = dis(gen);
		if (random == 1)
		{
			int f = 0;
			while (f!=4)
			{
				f = 0;
				if (world_->getOrganism(orgd->getX() + 1, orgd->getY()) != nullptr || orgd->getX() + 1 >= world_->getWidth())
				{
					f += 1;
					if (world_->getOrganism(orgd->getX() - 1, orgd->getY()) != nullptr || orgd->getX() - 1 < 0)
					{
						f += 1;
						if (world_->getOrganism(orgd->getX(), orgd->getY() + 1) != nullptr || orgd->getY() + 1 >= world_->getHeight())
						{
							f += 1;
							if (world_->getOrganism(orgd->getX(), orgd->getY() - 1) != nullptr || orgd->getY() - 1 < 0)
							{
								f += 1;
							}
						}
					}
				}
				uniform_int_distribution<> dis(0, 3);
				int rand = dis(gen);
				int orgX = orgd->getX();
				int orgY = orgd->getY();
				switch (rand) {
				case 0:
					orgX += 1;
					break;
				case 1:
					orgY += 1;
					break;
				case 2:
					orgX -= 1;
					break;
				case 3:
					orgY -= 1;
					break;
				}
				Organism* org1 = world_->getOrganism(orgX, orgY);
				if (orgX >= 0 && orgX < world_->getWidth() && orgY >= 0 && orgY < world_->getHeight() && org1 == nullptr)
				{
					orgd->setX(orgX);
					orgd->setY(orgY);
					return 0;
				}
			}
		}
		else
		{
			if (orga->getStrength() >= orgd->getStrength())
			{
				orgd->isAlive_ = false;
				this->world_->addKillComment(orga, orgd);
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
}

char Antelope::draw() const {
	return (char)65;
}

void Antelope::createNew(int x, int y) {
	World* world = this->getWorld();
	Organism* antelope = new Antelope(world, x, y);
	world->addOrganism(antelope);
}