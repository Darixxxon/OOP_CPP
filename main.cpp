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
#include <stdlib.h>
#include "fstream"
#include <random>

void load(World*& world);
void generateWorld(int height, int width, World*& world);

int main() {
	int width;
    int height;
    cout << "\033]0;Dariusz Morzuch 193074\007";
    cout << "Enter width of map:" << endl;
    cin >> width;
    cout << "Enter height of map:" << endl;
    cin >> height;

    World* world = new World(width, height);
	
    generateWorld(height, width, world);

	while (true) {
		system("CLS");
		world->legend();
		world->drawWorld();
        if (!world->makeTurn())
        {
            load(world);
        }
	}
	return 0;
}

void generateWorld(int height, int width, World*& world) {

    int r = (width * height) / 100;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> xhdis(0, width - 1);
    int x = xhdis(gen);
    uniform_int_distribution<> yhdis(0, height - 1);
    int y = yhdis(gen);
    Organism* human = new Human(world, x, y);
    world->addOrganism(human);
    for (int i = 0; i <= r; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            uniform_int_distribution<> xodis(0, width - 1);
            int x = xodis(gen);
            uniform_int_distribution<> yodis(0, height - 1);
            int y = yodis(gen);
            Organism* org = world->getOrganism(x, y);
            if (org == nullptr)
            {
                if(j==0)
                {
                    Organism* antelope = new Antelope(world, x, y);
                    world->addOrganism(antelope);
                }
                else if (j == 1)
                {
                    Organism* belladonna = new Belladonna(world, x, y);
                    world->addOrganism(belladonna);
                }
                else if (j == 2)
                {
                    Organism* fox = new Fox(world, x, y);
                    world->addOrganism(fox);
                }
                else if (j == 3)
                {
                    Organism* grass = new Grass(world, x, y);
                    world->addOrganism(grass);
                }
                else if (j == 4)
                {
                    Organism* guarana = new Guarana(world, x, y);
                    world->addOrganism(guarana);
                }
                else if (j == 5)
                {
                    Organism* sheep = new Sheep(world, x, y);
                    world->addOrganism(sheep);
                }
                else if (j == 6)
                {
                    Organism* sosnowsky = new Sosnowsky(world, x, y);
                    world->addOrganism(sosnowsky);
                }
                else if (j == 7)
                {
                    Organism* sow_thistle = new Sow_thistle(world, x, y);
                    world->addOrganism(sow_thistle);
                }
                else if (j == 8)
                {
                    Organism* turtle = new Turtle(world, x, y);
                    world->addOrganism(turtle);
                }
                else if (j == 9)
                {
                    Organism* wolf = new Wolf(world, x, y);
                    world->addOrganism(wolf);
                }
            }
        } 
    }
}

void load(World* &world) {
    system("CLS");
    world->organisms_.clear();
    ifstream in;
    string name;
    cout << "File name to load:" << endl;
    cin >> name;
    name += ".txt";
    in.open(name);
    bool alive;
    char type;
    int width, height, turn, num;
    in >> width;
    in >> height;
    delete world;
    world = new World(width, height);
    in >> turn;
    world->setTurnNumber(turn);
    in >> num;
    for (int i = 0; i < num; i++)
    {
        int x =0, y=0, strength=0, initiative=0, age=0, cd=0, dur=0;
        type = 0;
        in >> type;
        if (type == 'H' || type == 'h')
        {
            in >> x >> y;
            Organism* human = new Human(world, x, y);
            world->addOrganism(human);
            in >> strength >> initiative >> age >> alive >> cd >> dur;
            human->setStrength(strength);
            human->setInitiative(initiative);
            human->setAge(age);
            human->setIsAlive(alive);
            human->setCD(cd);
            human->setDUR(dur);
        }
        else if (type == 'W')
        {
            in >> x >> y;
            Organism* wolf = new Wolf(world, x, y);
            world->addOrganism(wolf);
            in >> strength >> initiative >> age >> alive;
            wolf->setStrength(strength);
            wolf->setInitiative(initiative);
            wolf->setAge(age);
            wolf->setIsAlive(alive);
        }
        else if (type == 'S')
        {
            in >> x >> y;
            Organism* sheep = new Sheep(world, x, y);
            world->addOrganism(sheep);
            in >> strength >> initiative >> age >> alive;
            sheep->setStrength(strength);
            sheep->setInitiative(initiative);
            sheep->setAge(age);
            sheep->setIsAlive(alive);
        }
        else if (type == 'F')
        {
            in >> x >> y;
            Organism* fox = new Fox(world, x, y);
            world->addOrganism(fox);
            in >> strength >> initiative >> age >> alive;
            fox->setStrength(strength);
            fox->setInitiative(initiative);
            fox->setAge(age);
            fox->setIsAlive(alive);
        }
        else if (type == 'T')
        {
            in >> x >> y;
            Organism* turtle = new Turtle(world, x, y);
            world->addOrganism(turtle);
            in >> strength >> initiative >> age >> alive;
            turtle->setStrength(strength);
            turtle->setInitiative(initiative);
            turtle->setAge(age);
            turtle->setIsAlive(alive);
        }
        else if (type == 'A')
        {
            in >> x >> y;
            Organism* antelope = new Antelope(world, x, y);
            world->addOrganism(antelope);
            in >> strength >> initiative >> age >> alive;
            antelope->setStrength(strength);
            antelope->setInitiative(initiative);
            antelope->setAge(age);
            antelope->setIsAlive(alive);
        }
        else if (type == (char)193)
        {
            in >> x >> y;
            Organism* grass = new Grass(world, x, y);
            world->addOrganism(grass);
            in >> strength >> initiative >> age >> alive;
            grass->setStrength(strength);
            grass->setInitiative(initiative);
            grass->setAge(age);
            grass->setIsAlive(alive);
        }
        else if (type == (char)207)
        {
            in >> x >> y;
            Organism* sow_thistle = new Sow_thistle(world, x, y);
            world->addOrganism(sow_thistle);
            in >> strength >> initiative >> age >> alive;
            sow_thistle->setStrength(strength);
            sow_thistle->setInitiative(initiative);
            sow_thistle->setAge(age);
            sow_thistle->setIsAlive(alive);
        }
        else if (type == (char)245)
        {
            in >> x >> y;
            Organism* guarana = new Guarana(world, x, y);
            world->addOrganism(guarana);
            in >> strength >> initiative >> age >> alive;
            guarana->setStrength(strength);
            guarana->setInitiative(initiative);
            guarana->setAge(age);
            guarana->setIsAlive(alive);
        }
        else if (type == (char)225)
        {
            in >> x >> y;
            Organism* belladonna = new Belladonna(world, x, y);
            world->addOrganism(belladonna);
            in >> strength >> initiative >> age >> alive;
            belladonna->setStrength(strength);
            belladonna->setInitiative(initiative);
            belladonna->setAge(age);
            belladonna->setIsAlive(alive);
        }
        else if (type == (char)197)
        {
            in >> x >> y;
            Organism* sosnowsky = new Sosnowsky(world, x, y);
            world->addOrganism(sosnowsky);
            in >> strength >> initiative >> age >> alive;
            sosnowsky->setStrength(strength);
            sosnowsky->setInitiative(initiative);
            sosnowsky->setAge(age);
            sosnowsky->setIsAlive(alive);
        }
    }
    in.close();
}
