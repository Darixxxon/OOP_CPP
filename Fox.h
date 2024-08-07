#pragma once
#include "Animal.h"
#include "Constants.h"

class Fox : public Animal {
public:
	Fox(World* world, int x, int y);
	~Fox();

	void action() override;
	char draw() const override;
	void createNew(int x, int y);
};