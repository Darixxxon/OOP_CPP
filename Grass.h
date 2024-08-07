#pragma once
#include "Plant.h"
#include "Constants.h"

class Grass : public Plant {
public:
	Grass(World* world, int x, int y);
	~Grass();

	char draw() const override;
	void createNew(int x, int y);
};