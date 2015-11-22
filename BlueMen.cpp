#include <iostream>
#include "BlueMen.hpp"


using namespace std;

BlueMen::BlueMen()
{
	creatureName = "The BlueMen";
	realName = "";

	atkdieSides = 10;
	atkRolls = 2;

	defdieSides = 6;
	defRolls = 3;

	armor = 3;
	strengthPoints = 12;
	totalStrength = strengthPoints;

	alive = true;
	points = 0;

	atkDie = new Die(atkdieSides);
	defDie = new Die(defdieSides);

}


/*Function: fight()
**Parameters: creature class object
**Description: When this function is called, it will call on the rollAtk function to generate the BlueMen's attack value.
**The opposing creature object will call on the defend function and pass the attack value as an intger argument to calculate the defence.
**Pre-condition: BlueMen's attack = 0;
**Post-condition: BlueMen's attack = rollAtk();
*/
void BlueMen::fight(Creature *enemy)
{
	int bluemenAtk = 0;

	bluemenAtk = rollAtk();

	enemy->defend(bluemenAtk);

}


/*Function: defend(int)
Parameters: integer argument
Description: When this function is called, it will calculate the damage taken received from the attacking creature.
Damage taken is equal to attacking creature's attack - defending creature's defence - defending creature's armor.
If the strength points is less than or equal to 0, the defending creature will die.
Pre-condition: BlueMen's damage taken =0
Post-condition: BlueMen's taken = creatureAtk-bluemenDef-armor
*/
void BlueMen::defend(int creatureAtk)
{

	int bluemenDef = 0;
	int damageTaken = 0;


	bluemenDef = rollDef();

	damageTaken = creatureAtk - bluemenDef - armor;


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

