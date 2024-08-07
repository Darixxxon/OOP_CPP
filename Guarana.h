#pragma once
#include "Plant.h"
#include "Constants.h"

class Guarana : public Plant {
public:
	Guarana(World* world, int x, int y);
	~Guarana();

	int collision(Organism* orga, Organism* orgd) override;
	char draw() const override;
	void createNew(int x, int y);
};