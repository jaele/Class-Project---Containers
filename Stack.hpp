#ifndef STACK_HPP
#define STACK_HPP
#include "Creature.hpp"


struct StackNode
{


	Creature *creature;
	StackNode *next;

	StackNode(Creature *creature, StackNode* next)
	{
		this->creature = creature;
		this->next = next;
	}
};



class Stack
{
private:
	// pointer to node class
	// top node starts empty
	StackNode *top;

public:
	// default constructor
	Stack();

	
	void add(Creature *);		// add an element to the top of stack
	void view();				// view data on the top of stack
	void remove();				// delete data in the top of stack

	Creature* getCreature();    // access creature on top of stack

	bool isEmpty();


};

#endif 
