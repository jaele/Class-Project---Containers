#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "Creature.hpp"

class Barbarian : public Creature
{

public:
	Barbarian();

	void fight(Creature *);
	void defend(int);

};

#endif
