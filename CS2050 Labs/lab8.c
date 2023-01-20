#include "lab8.h"

struct Node {
	Node *next;
	void *data;
};

struct Queue {
	Node *list;
	int size;
};

// O(1)
//allocate memory for our queue. If there isn't enough memory return NULL
//initialize the variable, list to null and size to 0 and return the queue
Queue * makeQueue()
{
	Queue * q;
	q = malloc(sizeof(Queue));
	if(!q){return NULL;}

	q->list = NULL;
	q->size = 0;

	return q;
}

// O(1)
//access the size member and return it
int getSize(Queue *q)
{
	return q->size;
}

// O(1)
//insert a node at the end of the queue, in this case the end is what q->list is pointing to
//if the queue is empty then the list will point to the new node
//if the queueu is not empty then the list will point to the new node but the new node will point to what the list was originally pointing to
//for both operations we add one to size which is stored in the queue struct
int enQueue(Queue *q, void *data)
{
	Node * insert;
	insert = malloc(sizeof(Node));
	if(!insert){return 1;}

	insert->data = data;
	insert->next = NULL;

	Node * list = q->list;

	if(list == NULL)
	{
		q->list = insert;
		q->size++;

		return 0;
	}
	else
	{
		insert->next = list;
		q->list = insert;

		q->size++;

		return 0;
	}
}

// O(n)
//dequeue removes the first person in the queue which happens to be at the end of the linked list
//we have to loop through and find the end and then return the object previous of the person first in the queue (or at the end of the linked list)
//when we find the end, the previous object points to what the last object is pointing to (NULL)
//return the object of the previous element and free the object first in the queue
//return NULL if the list is empty before or after we dequeue
void * deQueue(Queue *q)
{
	Node * node = q->list;

	while(node != NULL)
	{
		if(node->next == NULL)
		{
			Node * remove = node;

			q->list = node->next;
			q->size--;

			free(remove);

			return NULL;
		}
		else if(node->next->next == NULL)
		{
			void * tempObject = node->data;
			Node * remove = node->next;

			node->next = node->next->next;
			free(remove);

			q->size--;

			return tempObject;
		}
		node = node->next;
	}
	return NULL;
}

// O(n)
//loop through the queue until we find the end and return that object at the end
//returns NULL if queue is empty
void * peek(Queue *q)
{
	Node * node = q->list;
	if(!node){return NULL;}

	while(node != NULL)
	{
		if(node->next == NULL)
		{
			return node->data;
		}
		node = node->next;
	}
	return NULL;
}

// O(n)
//loop through until we find the end
//have temp nodes for each object and queue so we can free it after we move on
void freeQueue(Queue *q)
{
	Node * list = q->list;
	Node * temp;

	while(list != NULL)
	{
		temp = list;
		list = list->next;

		free(temp);
	}
	free(q);
}