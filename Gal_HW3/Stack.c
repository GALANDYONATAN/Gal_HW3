#include "Stack.h"

/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
	s->head = NULL;
}

void destroyStack(Stack* s)
{
	while (isEmptyStack(s) != 1)
	{
		pop(s);
	}
}

void push(Stack* s, char data)
{
	charNode* temp = (charNode*)calloc(1, sizeof(charNode));
	if (temp == NULL)
		return;
	temp->data = data;
	if (isEmptyStack(s) == 1)
	{
		s->head = temp;
		s->head->next = NULL;
	}
	else
	{
		temp->next = s->head;
		s->head = temp;
	}
}

char pop(Stack* s)
{
	if (isEmptyStack(s) == 1) // Check about it if neccessary
		return '~';
	char d = s->head->data;
	charNode* t = s->head;
	s->head = s->head->next;
	free(t);
	return d;
}


int isEmptyStack(const Stack* s)
{
	return s->head == NULL;
}

/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{
	int i = 0, j;
	Stack* s = (Stack*)calloc(1, sizeof(Stack));
	initStack(s);
	while (sentence[i] != '\0')
		if (sentence[i] == '#')
		{
			for (j = i + 1; sentence[j] != '#'; j++)
				push(s, sentence[j]);
			while (isEmptyStack(s) != 1)
				printf("%c", pop(s));
			i = j + 1;
		}
		else
		{
			printf("%c", sentence[i]);
			i++;
		}
	destroyStack(s);
	free(s);
}

int isPalindrome(Stack* s)
{
	if (isEmptyStack(s) != 0)
		return 0;
	charNode* first = s->head, * last = s->head, * running = s->head;
	while (last->next != NULL)
		last = last->next;
	while (first != last && last->next != first)
	{
		if (first->data != last->data)
			return 0;
		first = first->next;
		running = s->head;
		while (running->next != last)
			running = running->next;
		last = running;
	}
	return 1;
}

void rotateStack(Stack* s, int n)
{
	int cnt = 0;
	charNode* t = s->head, * f = s->head;
	while (t != NULL)
	{
		cnt++;
		t = t->next;
	}
	if (n <= 0 || n >= cnt)
		return;
	for (int i = 0; i < n; i++)
	{
		f = s->head;
		while (f->next->next != NULL)
			f = f->next;
		t = f->next;
		f->next = NULL;
		t->next = s->head;
		s->head = t;
	}
}