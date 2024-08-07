#include <iostream>
#include "Sosnowsky.h"
#include "Commentator.h"

Sosnowsky::Sosnowsky(World* world, int x, int y)
	: Plant(world, x, y, STRENGTH_SOSNOWSKY, INITIATIVE_PLANT, NAME_SOSNOWSKY, TYPE_PLANT) {}

Sosnowsky::~Sosnowsky() {}

void Sosnowsky::action()
{
	int nowX = this->getX();
	int nowY = this->getY();

	Organism* org = world_->getOrganism(nowX+1, nowY);
	if (org != nullptr && org->type_ == 'A')
	{
		this->collision(org, this);
	}
	org = world_->getOrganism(nowX-1, nowY);
	if (org != nullptr && org->type_ == 'A')
	{
		this->collision(org, this);
	}
	org = world_->getOrganism(nowX, nowY+1);
	if (org != nullptr && org->type_ == 'A')
	{
		this->collision(org, this);
	}
	org = world_->getOrganism(nowX, nowY-1);
	if (org != nullptr && org->type_ == 'A')
	{
		this->collision(org, this);
	}
}

int Sosnowsky::collision(Organism* orga, Organism* orgd)
{
	orga->isAlive_ = false;
	this->world_->addKillComment(orgd, orga);
	return 1;
}

char Sosnowsky::draw() const {
	return (char)DRAW_SOSNOWSKY;
}
