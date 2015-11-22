#include <iostream>
#include "Stack.hpp"


using namespace std;


Stack::Stack()
{

	top = NULL;
}

void Stack::add(Creature *creature)
{
	top = new StackNode(creature, top);
	
}

void Stack::view()
{
		StackNode *newNode = top;

		cout << "\nLoser's pile \n";

		do
		{
			cout << newNode->creature->getrealName() << endl;
			newNode = newNode->next;
		} while (newNode != NULL);
	
}


void Stack::remove()
{

	StackNode *temp;

	if (top == NULL)
	{
		cout << "Empty stack. No more to remove. " << endl << endl;
	}

	else
	{

		temp = top;
		top = top->next;

		delete temp;
		
	}

}

Creature* Stack::getCreature()
{
	if (top == NULL)
	{
		cout << "There's no characters in the pile! " << endl;
		return 0;
	}

	else
	{
		return top->creature;
	}
}




bool Stack::isEmpty()
{

	if (top == NULL)
	{
		return true;
	}

	else
	{
		return false;
	}


}
