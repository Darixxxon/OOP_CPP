#pragma once
#include "Animal.h"
#include "Constants.h"

class Wolf : public Animal {
public:
	Wolf(World* world, int x, int y);
	~Wolf();

	char draw() const override;
	void createNew(int x, int y);
};