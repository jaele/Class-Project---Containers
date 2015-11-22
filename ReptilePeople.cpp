#include <iostream>
#include "ReptilePeople.hpp"

using namespace std;

ReptilePeople::ReptilePeople()
{
	creatureName = "The ReptilePeople";

	realName = "";

	atkdieSides = 6;
	atkRolls = 3;

	defdieSides = 6;
	defRolls = 1;

	armor = 7;
	strengthPoints = 18;
	totalStrength = strengthPoints;


	alive = true;
	points = 0;

	atkDie = new Die(atkdieSides);
	defDie = new Die(defdieSides);

}

/*Function: fight()
**Parameters: creature class object
**Description: When this function is called, it will call on the rollAtk function to generate the ReptilePeople's attack value.
**The opposing creature object will call on the defend function and pass the attack value as an intger argument to calculate the defence.
**Pre-condition: ReptilePeople's attack = 0;
**Post-condition: ReptilePeople's attack = rollAtk();
*/
void ReptilePeople::fight(Creature *enemy)
{
	int reptileAtk = 0;

	reptileAtk = rollAtk();

	enemy->defend(reptileAtk);

}


/*Function: defend(int)
**Parameters: integer argument
**Description: When this function is called, it will calculate the damage taken received from the attacking creature.
**Damage taken is equal to attacking creature's attack - defending creature's defence - defending creature's armor.
**If the strength points is less than or equal to 0, the defending creature will die.
**Pre-condition: ReptilePeople's damage taken =0
**Post-condition: ReptilePeople's taken = creatureAtk-reptileDef-armor
*/
void ReptilePeople::defend(int creatureAtk)
{

	int reptileDef = 0;
	int damageTaken = 0;


	reptileDef = rollDef();

	damageTaken = creatureAtk - reptileDef - armor;


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
