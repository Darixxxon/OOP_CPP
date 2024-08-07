#pragma once
#include "Animal.h"
#include "Constants.h"

class Antelope : public Animal {
public:
	Antelope(World* world, int x, int y);
	~Antelope();

	void action() override;
	int collision(Organism* orga, Organism* orgd) override;
	char draw() const override;
	void createNew(int x, int y);
};