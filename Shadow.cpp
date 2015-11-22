#include "Shadow.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

Shadow::Shadow()
{
	creatureName = "The Shadow";
	realName = "";

	atkdieSides = 10;
	atkRolls = 2;

	defdieSides = 6;
	defRolls = 1;

	armor = 0;
	strengthPoints = 12;
	totalStrength = strengthPoints;

	alive = true;
	points = 0;

	atkDie = new Die(atkdieSides);
	defDie = new Die(defdieSides);

}


/*Function: fight()
**Parameters: creature class object
**Description: When this function is called, it will call on the rollAtk function to generate the Shadow's attack value.
**The opposing creature object will call on the defend function and pass the attack value as an intger argument to calculate the defence.
**Pre-condition: Shadow's attack = 0;
**Post-condition: Shadow's attack = rollAtk();
*/
void Shadow::fight(Creature *enemy)
{
	int shadowAtk = 0;

	shadowAtk = rollAtk();

	enemy->defend(shadowAtk);

}

/*Function: defend(int)
**Parameters: integer argument
**Description: When this function is called, it will calculate the damage taken received from the attacking creature.
**Damage taken is equal to attacking creature's attack - defending creature's defence - defending creature's armor.
**Shadow has the ability to "hide" or become "invincibe" 90% of the time.
**Pre-condition: Shadow's damage taken =0
**Post-condition: shadow's damage taken = creatureAtk-shadowDef-armor
*/
void Shadow::defend(int creatureAtk)
{

	// set to not take damage 90% of the time as in the radio play
	// it's basically invincible

	int armor = 0;

	if (rand() % 100 < 90)
	{
		armor = 999;
	}

	else
	{
		armor = 0;
	}


	int shadowDef = 0;
	int damageTaken = 0;

	shadowDef = rollDef();

	damageTaken = creatureAtk - shadowDef - armor;


	if (damageTaken > 0)
	{
		cout << damageTaken << " damage!";
	}

	else if (damageTaken <= 0)
	{
		cout << "no damage, 'The Shadow' has vanished!";
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
