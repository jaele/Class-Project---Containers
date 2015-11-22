#include <iostream>
#include "Barbarian.hpp"

using namespace std;
Barbarian::Barbarian()
{
	creatureName = "The Barbarian";
	realName = "";

	atkdieSides = 6;
	atkRolls = 2;

	defdieSides = 6;
	defRolls = 2;

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
**Description: When this function is called, it will call on the rollAtk function to generate the Barbarian's attack value.
**The opposing creature object will call on the defend function and pass the attack value as an intger argument to calculate the defence.
**Pre-condition: Barbarian's attack = 0;
**Post-condition: Barbarian's attack = rollAtk();
*/
void Barbarian::fight(Creature *enemy)
{
	int barbAtk = 0;

	barbAtk = rollAtk();

	enemy->defend(barbAtk);

}


/*Function: defend(int)
**Parameters: integer argument
**Description: When this function is called, it will calculate the damage taken received from the attacking creature.
**Damage taken is equal to attacking creature's attack - defending creature's defence - defending creature's armor.
**If the strength points is less than or equal to 0, the defending creature will die.
**Pre-condition: Barbarian's damage taken =0
**Post-condition: Barbarian's damage taken = creatureAtk-barbDef-armor
*/
void Barbarian::defend(int creatureAtk)
{

	int barbDef = 0;
	int damageTaken = 0;


	barbDef = rollDef();

	damageTaken = creatureAtk - barbDef - armor;


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
