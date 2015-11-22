#ifndef REPTILEPEOPLE_HPP
#define REPTILEPEOPLE_HPP
#include "Creature.hpp"


class ReptilePeople : public Creature
{
public:

	ReptilePeople();

	void fight(Creature *);
	void defend(int);

};

#endif
