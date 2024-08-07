#pragma once
#include "Animal.h"
#include "Constants.h"

class Sheep : public Animal {
public:
    Sheep(World* world, int x, int y);
    ~Sheep();

    char draw() const override;
    void createNew(int x, int y);
};