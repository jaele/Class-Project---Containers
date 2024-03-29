#include <iostream>
#include "Creature.hpp"

using namespace std;

string Creature::getcreatureName()
{
	return creatureName;
}


int Creature::getstrengthPoint()
{
	return strengthPoints;
}


bool Creature::liveCreature()
{

	return alive;
}

/*Function: rollAtk()
**Parameters: none
**Description: When a creature calls on this function, it will roll the attack die based on the creature's value
**and return that attack value
**Pre-condition: creature's attack = 0;
**Post-condition: creature's attack = value generated by die roll
*/

int Creature::rollAtk()
{
	int creatureAtk = 0;
	int atkCounter = 0;

	for (int i = 0; i < atkRolls; i++)
	{
		atkCounter += atkDie->rollDie();
	}

	creatureAtk = atkCounter;

	return creatureAtk;
}


/*Function: rollDef()
**Parameters: none
**Description: When a creature calls on this function, it will roll the defence die based on the creature's value
**and return that defence value
**Pre-condition: creature defence = 0;
**Post-condition: creature defence = value generated by die roll
*/
int Creature::rollDef()
{
	int creatureDef = 0;
	int defCounter = 0;

	for (int i = 0; i < defRolls; i++)
	{
		defCounter += defDie->rollDie();
	}

	creatureDef = defCounter;

	return creatureDef;
}




void Creature::setrealName(string realName)
{

	this->realName = realName;
}


string Creature::getrealName()
{
	return realName;
}



void Creature::replenish()
{

	if (strengthPoints > totalStrength)
	{
		strengthPoints = totalStrength;
	}


	int winBonus = (rand() % 5) + 1;
	strengthPoints += winBonus;


}



void Creature::addPoint()
{
	points++;
}

int Creature::getPoints()
{
	return points;
}


bool Compare::operator()(Creature *creature1, Creature *creature2)
{
	if (creature1->getPoints() >= creature2->getPoints())
	{
		return false;
	}

	else
	{
		return true;
	}
}
