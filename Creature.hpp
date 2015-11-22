#ifndef CREATURE_HPP
#define CREATURE_HPP
#include <ctime>
#include <cstdlib>
#include <string>
//#include "Die.hpp"

using namespace std;

// base class
class Creature
{
protected:

	// creature stats
	string creatureName;

	string realName;

	int atkdieSides;
	int atkRolls;

	int defdieSides;
	int defRolls;

	int armor;
	int strengthPoints;
	int totalStrength;

	// creature condition
	bool alive;

	int points;


	class Die
	{
	private:
		int sides;

	public:
		Die(int numSides)
		{
			sides = numSides;
		}

		int rollDie()
		{

			int val = rand() % sides + 1;
			return val;
		}
	};

	Die *atkDie;
	Die *defDie;

public:

	// get the name of creature
	virtual string getcreatureName();

	// get the current strength points of the creature
	virtual int getstrengthPoint();


	// return condition of creature
	virtual bool liveCreature();

	// roll die to return attack and defense value
	virtual int rollAtk();
	virtual int rollDef();


	// fight and defend methods
	// pure virtual functions
	virtual void fight(Creature *) = 0;
	virtual void defend(int) = 0;

	virtual void setrealName(string);
	virtual string getrealName();

	virtual void replenish();

	virtual void addPoint();
	virtual int getPoints();



};


class Compare
{
public:
	bool operator()(Creature*, Creature*);
};




#endif 
