#pragma once
#include "Organism.h"
#include "Constants.h"

class Plant : public Organism {
public:
    Plant(World* world, int x, int y, int strength, int initiative, string name, char type);
    virtual ~Plant();

    void action() override;
    int collision(Organism* orga, Organism* orgd) override;
    virtual void createNew(int x, int y) = 0;
};