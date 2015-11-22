#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "Creature.hpp"



class BlueMen : public Creature
{

public:

	BlueMen();

	void fight(Creature *);
	void defend(int);
};

#endif
