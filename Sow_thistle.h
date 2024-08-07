#pragma once
#include "Plant.h"
#include "Constants.h"

class Sow_thistle : public Plant {
public:
	Sow_thistle(World* world, int x, int y);
	~Sow_thistle();

	void action() override;
	char draw() const override;
	void createNew(int x, int y);
};