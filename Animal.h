#pragma once
#include "Organism.h"
#include "Constants.h"
#include <vector>

class Animal : public Organism {
public:
	Animal(World* world, int x, int y, int strength, int initiative, string name, char type);
	virtual ~Animal();

	void action() override;
	int collision(Organism* orga, Organism* orgd) override;
	virtual char draw() const = 0;
	virtual void createNew(int x, int y) = 0;
	void detectFree(int x, int y);
};