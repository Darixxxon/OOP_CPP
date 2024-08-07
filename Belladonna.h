#pragma once
#include "Plant.h"
#include "Constants.h"

class Belladonna : public Plant {
public:
	Belladonna(World* world, int x, int y);
	~Belladonna();

	int collision(Organism* orga, Organism* orgd) override;
	char draw() const override;
	void createNew(int x, int y);
};