#pragma once
#include "Animal.h"
#include "Constants.h"

class Human : public Animal {
public:
    Human(World* world, int x, int y);
    ~Human();

    void action() override;
    char draw() const override;
    void createNew(int x, int y) {}
    void ability();

protected:
    int ability_cd_ = 0;
    int ability_dur_ = 0;
};