#include <iostream>	
#include "Queue.hpp"

using namespace std;


Queue::Queue()
{
	front = NULL;
	back = NULL;
}

Queue::~Queue()
{
	QueueNode *head = front;

	while (!(head == NULL))
	{
		QueueNode *temp = head->next;
		delete head;
		head = temp;
	}
}


void Queue::add(Creature *creature)
{
	if (front == NULL)
	{
		front = new QueueNode(creature, NULL);
		back = front;
	}

	else
	{
		back->next = new QueueNode(creature, NULL);
		back = back->next;
	}
}


void Queue::view()
{
	
		QueueNode *newNode = front;

		cout << "\nLine up \n";
		do
		{
			cout << newNode->creature->getrealName() << endl;
			newNode = newNode->next;

		} while (newNode != NULL);

		// book example to view the entire node
		/*ListNode *ptr = numberList;
		 while (ptr != NULL) 
		 {
			cout << ptr->value << " "; // process node
			ptr = ptr->next;			// move to next node
			}
		*/

}


void Queue::remove()
{

	QueueNode *temp;

	if (front == NULL)
	{
		cout << "Empty queue. No more to remove. " << endl << endl;
	}

	else
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}


Creature* Queue::getCreature()
{
	if (front == NULL)
	{
		cout << "There's no characters in the line! " << endl;
		return 0;
	}

	else
	{
		return front->creature;
	}
}


bool Queue::isEmpty()
{

	if (front == NULL)
	{
		return true;
	}

	else
	{
		return false;
	}

	
}


void Queue::addSort(Creature *creatures)
{

	QueueNode *newNode, *previousNode;

	if (front == NULL || front->creature->getPoints() <= creatures->getPoints())
	{

		front = new QueueNode(creatures, front);

	}

	else
	{
		previousNode = front;
		newNode = front->next;

		while (newNode != NULL && newNode->creature->getPoints() > creatures->getPoints())
		{
			previousNode = newNode;
			newNode = newNode->next;
		}

		previousNode->next = new QueueNode(creatures, newNode);
	}
}

