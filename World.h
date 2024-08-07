#pragma once
#include "Commentator.h"
#include <vector>
#include <iostream>
using namespace std;

class Organism;

class World {
public:
	World(int width, int height);
	~World();
	vector<Organism*> organisms_;
	vector<string> commentator_;

	int getWidth() const ;
	int getHeight() const;
	int getTurnNumber() const;
	Organism* getOrganism(int x, int y) const;
	void addOrganism(Organism* org);
	void setTurnNumber(int turnNumber);

	void legend();
	int makeTurn();
	void drawWorld() const;
	void save();

	void comment();
	void addEatComment(Organism* first, Organism* second);
	void addKillComment(Organism* first, Organism* second);
	void clearComm();

private:
	int width_;
	int height_;
	int turnNumber_;
};