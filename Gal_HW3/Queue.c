#include "Queue.h"
#define NULLPTR NULL

/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q)
{
	q->head = NULLPTR;
	q->tail = NULLPTR;
}

void destroyQueue(Queue* q)
{
	while (isEmptyQueue(q) == 0)
		dequeue(q);
}

void enqueue(Queue* q, unsigned int data)
{
	intNode* ptr = (intNode*)malloc(sizeof(intNode));
	if (ptr == NULL)
		return;
	ptr->data = data;
	ptr->next = NULL;
	if (isEmptyQueue(q))
		q->head = ptr;
	else
		q->tail->next = ptr;
	q->tail = ptr;
}

unsigned int dequeue(Queue* q)
{
	if (isEmptyQueue(q))
		return 0;
	unsigned int num = q->head->data;
	if (q->head == q->tail)
	{
		free(q->head);
		q->head = NULL;
		q->tail = NULL;
	}
	else
	{
		intNode* p = q->head;
		q->head = q->head->next;
		free(p);
	}
	return num;
}

int isEmptyQueue(const Queue* q)
{
	return q->head == NULL;
	//return q->tail == NULL;
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	if (isEmptyQueue(q) == 0 && q->head != q->tail)
	{
		intNode* p = q->head;
		while (p->next != q->tail)
			p = p->next;
		p->next = NULL;
		q->tail->next = q->head;
		q->head = q->tail;
		q->tail = p;
	}
}

intNode* SwitchDirection(intNode* head)
{
	intNode* prev = NULL, * current = head, * next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}

void cutAndReplace(Queue* q)
{
	int cnt = 0, sum = 0;
	intNode* p = q->head, * new_node = NULL, * end = q->head;
	while (p != NULL)
	{
		cnt++;
		sum += p->data;
		p = p->next;
	}
	// all this for odd number of items in linked list
	if (cnt % 2 != 0)
	{
		sum /= cnt;
		new_node = (intNode*)malloc(sizeof(intNode));
		if (new_node == NULL)
			return;
		new_node->data = sum;
		new_node->next = NULL;
		q->tail->next = new_node;
		q->tail = new_node;
		cnt++;
	}
	// all this for odd number of items in linked list
	// now rotate the linked list.
	p = q->head;
	sum = 0;
	while (sum < cnt / 2)
	{
		if (sum == cnt / 2 - 1)
		{
			end = p;
			p = p->next;
			end->next = NULL;
		}
		else
			p = p->next;		
		sum++;
	}
	p = SwitchDirection(p);
	new_node = p;
	while (new_node->next != NULL)
		new_node = new_node->next;
	new_node->next = q->head;
	q->head = p;
	new_node = q->head;
	while (new_node->next != NULL)
		new_node = new_node->next;
	q->tail = new_node;
}

void sortKidsFirst(Queue* q)
{
	int num, cnt =0;
	intNode* p = q->head, * node = q->head;
	while (p != NULL)
	{
		p = p->next;
		cnt++;
	}
	for (int i = 0; i < cnt; i++)
	{
		p = q->head;
		while (p->next != NULL)
		{
			if (p->data > p->next->data)
			{
				num = p->data;
				p->data = p->next->data;
				p->next->data = num;
			}
			p = p->next;
		}
	}
}