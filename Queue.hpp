#ifndef  QUEUE_HPP
#define  QUEUE_HPP
#include "Creature.hpp"


struct QueueNode
{
	Creature *creature;
	QueueNode *next;

	QueueNode(Creature* creature, QueueNode* next = NULL)
	{
		this->creature = creature;
		this->next = next;
	}

};

class Queue
{
private:
	//friend class SortedQueue;
	// pointers to node class
	QueueNode *front;
	QueueNode *back;

public:
	// default constructor
	Queue();
	~Queue();

	
	void add(Creature *);		// add an element to the back of the queue
	void view();				// view all data in the queue
	void remove();				// remove data from front of queue

	Creature* getCreature();	// access first creature in queue	

	bool isEmpty();

	void addSort(Creature *);

};

/*
class SortedQueue: public Queue
{
public:

	void add(Creature* creatures)
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
};

*/

#endif
