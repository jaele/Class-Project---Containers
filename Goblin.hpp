#ifndef GOBLIN_HPP
#define GOBLIN_HPP
#include "Creature.hpp"


class Goblin : public Creature
{

private:
	// special goblin ability
	bool cutAchilles;

public:

	Goblin();

	void fight(Creature *);
	void defend(int);

};

#endif
