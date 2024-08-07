#pragma once
#include "World.h"

class Organism {
public:
	Organism(World* world, int x, int y, int strength, int initiative, string name, char type);
	virtual ~Organism();

	virtual void action() = 0;
	virtual int collision(Organism* orga, Organism* orgd) = 0;
	virtual char draw() const = 0;
	virtual void createNew(int x, int y) = 0;

	int getX() const;
	int getY() const;
	int getStrength() const;
	int getInitiative() const;
	int getAge() const;
	World* getWorld() const;
	int getCD() const;
	int getDUR() const;
	int getIsAlive() const;
	string getName() const;

	void setStrength(int strength);
	void setInitiative(int initiative);
	void setX(int x);
	void setY(int y);
	void setAge(int age);
	void setWorld(World* world);
	void setCD(int ability_cd);
	void setDUR(int ability_dur);
	void setIsAlive(bool isAlive);
	void setName(string name);

	bool isAlive_;
	int age_;
	string name_;
	char type_;
	int ability_cd_;
	int ability_dur_;

protected:
	int strength_;
	int initiative_;
	int x_;
	int y_;
	World* world_;
};