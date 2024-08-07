#include <iostream>
#include <conio.h>
#include "Human.h"
#include "World.h"

Human::Human(World* world, int x, int y)
    : Animal(world, x, y, STRENGTH_HUMAN, INITIATIVE_HUMAN,NAME_HUMAN, TYPE_ANIMAL) {}

Human::~Human() {}

void Human::action()
{
    if (this->ability_cd_ > 0)
    {
        if (this->ability_dur_ > 0)
        {
            this->setStrength(this->getStrength() - 1);
            this->ability_dur_--;
        }
        this->ability_cd_--;
    }
    
    std::cout << "Enter movement direction (arrows): ";
    int newX = x_;
    int newY = y_;
    char a = NULL;
    a = _getch();
    if (a == R_KEY && this->ability_cd_==0)
    {
        ability();
        a = _getch();
    }
    else if (a == S_KEY)
    {
        world_->save();
        a = _getch();
    }
    else if (a == L_KEY)
    {
        this->setStrength(1);
        return;
    }
    a = _getch();
    switch (a) {
    case RIGHT_ARROW:
        newX += 1;
        break;
    case UP_ARROW:
        newY += 1;
        break;
    case LEFT_ARROW:
        newX -= 1;
        break;
    case DOWN_ARROW:
        newY -= 1;
        break;
    default:
        break;
    }

    if (newX >= 0 && newX < world_->getWidth() && newY >= 0 && newY < world_->getHeight()) {
        Organism* org = world_->getOrganism(newX, newY);
        if (org == nullptr) {
            x_ = newX;
            y_ = newY;
        }
        else {
            if (org->collision(this, org)) {
                x_ = newX;
                y_ = newY;
            }
        }
    }
}


char Human::draw() const{
    if (this->ability_dur_ > 0)
    {
        return (char)DRAW_SUPER_HUMAN;
    }
    else
    {
        return (char)DRAW_NORMAL_HUMAN;
    }
}

void Human::ability() {
    //magical potion
    this->setStrength(ABILITY_SET_STRENGTH);
    this->ability_cd_ = ABILITY_COOLDOWN;
    this->ability_dur_ = ABILITY_DURATION;
}