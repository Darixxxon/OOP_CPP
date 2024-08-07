#include "Organism.h"
#include "World.h"

Organism::Organism(World* world, int x, int y, int strength, int initiative, string name, char type)
    : x_(x), y_(y), strength_(strength), initiative_(initiative), world_(world), age_(0), isAlive_(true), name_(name), type_(type)
{
}

Organism::~Organism()
{
}

int Organism::getX() const
{
    return x_; 
}

int Organism::getY() const
{
    return y_;
}

int Organism::getStrength() const
{
    return strength_;
}

int Organism::getInitiative() const
{
    return initiative_;
}

int Organism::getAge() const
{
    return age_;
}

World* Organism::getWorld() const
{
    return world_;
}

int Organism::getCD() const
{
    return ability_cd_;
}

int Organism::getDUR() const
{
    return ability_dur_;
}

int Organism::getIsAlive() const
{
    return isAlive_;
}

string Organism::getName() const
{
    return name_;
}

void Organism::setX(int x)
{
    this->x_ = x;
}

void Organism::setY(int y)
{
    this->y_ = y;
}

void Organism::setStrength(int strength)
{
    this->strength_ = strength;
}

void Organism::setInitiative(int initiative)
{
    initiative_ = initiative;
}

void Organism::setAge(int age)
{
    age_ = age;
}

void Organism::setWorld(World* world)
{
    this->world_ = world;
}

void Organism::setCD(int ability_cd)
{
    this->ability_cd_ = ability_cd;
}

void Organism::setDUR(int ability_dur)
{
    this->ability_dur_ = ability_dur;
}

void Organism::setIsAlive(bool isAlive)
{
    this->isAlive_ = isAlive;
}

void Organism::setName(string name)
{
    this->name_ = name;
}