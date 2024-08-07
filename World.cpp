#include "World.h"
#include "Human.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Grass.h"
#include "Sow_thistle.h"
#include "Guarana.h"
#include "Belladonna.h"
#include "Sosnowsky.h"
#include "Organism.h"
#include "conio.h"
#include "fstream"
#include "Commentator.h"
#include <algorithm>

World::World(int width, int height) : width_(width), height_(height), turnNumber_(0) {}

World::~World() {
    for (Organism* organism : organisms_) {
        delete organism;
    }
}

void World::addOrganism(Organism* organism) {
    organisms_.push_back(organism);
    organism->setWorld(this);
}

void World::legend(){
    cout << "\033]0;Dariusz Morzuch 193074\007";
    cout << "Legend:" << endl;
    cout << (char)DRAW_NORMAL_HUMAN << "/" << (char)DRAW_SUPER_HUMAN <<"  = Human" << endl;
    cout << (char)DRAW_WOLF << "    =  Wolf" << endl;
    cout << (char)DRAW_SHEEP << "    =  Sheep" << endl;
    cout << (char)DRAW_FOX << "    =  Fox" << endl;
    cout << (char)DRAW_TURTLE << "    =  Turtle" << endl;
    cout << (char)DRAW_ANTELOPE << "    =  Antelope" << endl;
    cout << (char)DRAW_GRASS << "    =  Grass" << endl;
    cout << (char)DRAW_SOW_THISTLE << "    =  Sow thisle" << endl;
    cout << (char)DRAW_GUARANA << "    =  Guarana" << endl;
    cout << (char)DRAW_BELLADONNA << "    =  Belladona" << endl;
    cout << (char)DRAW_SOSNOWSKY << "    =  Sosnowsky's hogweed" << endl;
    cout << "Press 'r' to use special ability" << endl;
    cout << "Press 's' to save game" << endl;
    cout << "Press 'l' to load game" << endl;
}

void World::drawWorld() const {
    for (int i = 0; i < width_ + 2; i++) {
        std::cout << (char)DRAW_WALL;
    }
    std::cout << std::endl;

    for (int y = 0; y < height_; y++) {
        std::cout << (char)DRAW_WALL;
        for (int x = 0; x < width_; x++) {
            Organism* organism = getOrganism(x, y);
            if (organism != nullptr) {
                std::cout << organism->draw();
            }
            else {
                std::cout << (char)DRAW_SPACE;
            }
        }
        std::cout << (char)DRAW_WALL << std::endl;
    }

    for (int i = 0; i < width_ + 2; i++) {
        std::cout << (char)DRAW_WALL;
    }
    std::cout << std::endl;
}

Organism* World::getOrganism(int x, int y) const {
    for (Organism* organism : organisms_) {
        if (organism->getX() == x && organism->getY() == y) {
            return organism;
        }
    }
    return nullptr;
}

int World::makeTurn() {
    turnNumber_++;
    // sort organisms in descending order based on initiative and age
    std::sort(organisms_.begin(), organisms_.end(), [](Organism* a, Organism* b) {
        if(a->getInitiative() != b->getInitiative()){
            return a->getInitiative() > b->getInitiative();
        }
        else {
            return a->getAge() > b->getAge();
        }
        });
    if(turnNumber_ != 0)
    {
        comment();
    }
    clearComm();
    Organism* organism = organisms_[0];
    for (int i = 0; i < organisms_.size(); i++)
    {
        organism = organisms_[i];
            if (organism->age_ > 0 && organism->isAlive_)
            {
                if (organism->draw() == (char)DRAW_NORMAL_HUMAN || organism->draw() == (char)DRAW_SUPER_HUMAN)
                {
                    this->comment();
                }
                organism->action();
                if ((organism->draw() == (char)DRAW_NORMAL_HUMAN || organism->draw() == (char)DRAW_SUPER_HUMAN) && organism->getStrength() == 1)
                {
                    return 0;
                }
            }
    }
    for (int i = 0; i < organisms_.size(); i++) {
        organism = organisms_[i];
        if (!organism->isAlive_) {
            organisms_.erase(organisms_.begin() + i);
        }
        i++;
        organism->age_++;
    }
    return 1;
}

int World::getWidth() const {
    return width_;
}

int World::getHeight() const {
    return height_;
}

int World::getTurnNumber() const {
    return turnNumber_;
}
void World::setTurnNumber(int turnNumber) {
    int turnNumber_ = turnNumber;
}

void World::save() {
    system("CLS");
    cout << "File name to save:" << endl;
    ofstream out;
    string name;
    cin >> name;
    name += ".txt";
    out.open(name);

    out << getWidth() << endl;
    out << getHeight() << endl;
    out << getTurnNumber() << endl;

    Organism* organism = organisms_[0];
    out << organisms_.size() << endl;
    for (int i = 0; i < organisms_.size(); i++)
    {
        organism = organisms_[i];
        if (organism != nullptr)
        {
            out << organism->draw() << endl;
            out << organism->getX() << endl;
            out << organism->getY() << endl;
            out << organism->getStrength() << endl;
            out << organism->getInitiative() << endl;
            out << organism->getAge() << endl;
            out << organism->getIsAlive() << endl;
            if (organism->draw() == 'h' || organism->draw() == 'H')
            {
                out << organism->getCD() << endl;
                out << organism->getDUR() << endl;
            }
        }
    }
    out.close();
}

void World::comment()
{
    cout << "Commentator:" << endl;
    for (string comment : commentator_) {
        cout << comment << endl;
    }
}

void World::addKillComment(Organism* first, Organism* second) {
    string comment = first->getName() + " killed " + second->getName();
    commentator_.push_back(comment);
}

void World::addEatComment(Organism* first, Organism* second) {
    commentator_.push_back(first->getName() + " ate " + second->getName());
}

void World::clearComm() {
    commentator_.clear();
}