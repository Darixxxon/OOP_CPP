#pragma once
#pragma once
#include "Plant.h"
#include "Constants.h"

class Sosnowsky : public Plant {
public:
	Sosnowsky(World* world, int x, int y);
	~Sosnowsky();

	void action() override;
	int collision(Organism* orga, Organism* orgd) override;
	char draw() const override;
	void createNew(int x, int y) {}
};