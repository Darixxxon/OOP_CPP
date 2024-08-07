#pragma once
#include "Animal.h"
#include "Constants.h"

class Turtle : public Animal {
public:
	Turtle(World* world, int x, int y);
	~Turtle();

	void action() override;
	int collision(Organism* orga, Organism* orgd) override;
	char draw() const override;
	void createNew(int x, int y);
};