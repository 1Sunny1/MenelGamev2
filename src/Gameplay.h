#ifndef GAMEPLAY_H_
#define GAMEPLAY_H_
#include "Hero.h"
#include "Game.h"
class Gameplay : public Game {
public:
	void playerWentLeft();
	void playerWentRight();
	void fight(Hero &);
};

#endif
