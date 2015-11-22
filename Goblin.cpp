#include <iostream>
#include "Goblin.hpp"

using namespace std;

Goblin::Goblin()
{
	creatureName = "The Goblin";
	realName = "";

	atkdieSides = 6;
	atkRolls = 2;

	defdieSides = 6;
	defRolls = 1;

	armor = 3;
	strengthPoints = 8;
	totalStrength = strengthPoints;

	alive = true;
	cutAchilles = false;
	points = 0;

	atkDie = new Die(atkdieSides);
	defDie = new Die(defdieSides);
}


/*Function: fight()
**Parameters: creature class object
**Description: When this function is called, it will call on the rollAtk function to generate the Goblin's attack value.
**The opposing creature object will call on the defend function and pass the attack value as an intger argument to calculate the defence.
**Goblin has special ability that if it rolled a 12 attack value, the opposing creature whos not another goblin
**will have their attack reduced in half for the entire fight.
**Pre-condition: Goblin's attack = 0;
**Post-condition: Goblin's attack = rollAtk();
*/
void Goblin::fight(Creature *enemy)
{
	int goblinAtk = 0;

	goblinAtk = rollAtk();


	if (goblinAtk == 12 && enemy->getcreatureName() != "The Goblin")
	{
		cutAchilles = true;
	}

	enemy->defend(goblinAtk);
}

/*Function: defend(int)
**Parameters: integer argument
**Description: When this function is called, it will calculate the damage taken received from the attacking creature.
**Damage taken is equal to attacking creature's attack - defending creature's defence - defending creature's armor.
**If the strength points is less than or equal to 0, the defending creature will die.
**The goblin will receive half the damage when it's ability is triggered.
**Pre-condition: goblin's damage taken =0
**Post-condition: goblin's damage taken = creatureAtk-goblinDef-armor
*/
void Goblin::defend(int creatureAtk)
{

	if (cutAchilles == true)
	{
		creatureAtk = creatureAtk / 2;
	}


	int goblinDef = 0;
	int damageTaken = 0;

	goblinDef = rollDef();

	damageTaken = creatureAtk - goblinDef - armor;


	if (damageTaken > 0)
	{
		cout << damageTaken << " damage!";
	}

	else if (damageTaken <= 0)
	{
		cout << "no damage!";
	}

	if (damageTaken > 0)
	{

		strengthPoints -= damageTaken;

		if (strengthPoints <= 0)
		{
			strengthPoints = 0;

			alive = false;
		}

		else if (strengthPoints > 0)
		{

			alive = true;
		}
	}

}
