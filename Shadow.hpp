#ifndef Shadow_HPP
#define Shadow_HPP
#include "Creature.hpp"


class Shadow : public Creature
{
public:

	Shadow();

	void fight(Creature *);
	void defend(int);

};

#endif
