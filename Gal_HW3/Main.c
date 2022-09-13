#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"
#include "Queue.h"

void main()
{
	char sentence1[] = "Remem#reb# thi#carp s#tice";
	printf("Before: %s\nAfter: ", sentence1);

	flipBetweenHashes(sentence1);
	printf("\n");
	char sentence2[] = "#meR#embe#siht r# practice";
	printf("Before: %s\nAfter: ", sentence2);

	flipBetweenHashes(sentence2);

	printf("\n\n");
	Stack* s = (Stack*)malloc(1 * sizeof(Stack));
	initStack(s);
	push(s, 'r');
	push(s, 'a');
	push(s, 'd');
	push(s, 'd');
	push(s, 'a');
	push(s, 'r');
	if (isPalindrome(s) == 1)
		printf("The stack is polindrom!");
	else
		printf("The stack is NOT a polindrom!");
	destroyStack(s);
	free(s);

	printf("\n\n");
	s = (Stack*)malloc(1 * sizeof(Stack));
	initStack(s);
	push(s, '5');
	push(s, '4');
	push(s, '3');
	push(s, '2');
	push(s, '1');
	printf("insert how many rotates we need to do: ");
	int randomnum;
	scanf("%d", &randomnum);
	printf("Before Rotate:\n");
	charNode* ptr = s->head;
	while (ptr)
	{
		printf("%c ", ptr->data);
		ptr = ptr->next;
	}
	rotateStack(s, randomnum);
	printf("\nAfter Rotate:\n");
	ptr = s->head;
	while (ptr)
	{
		printf("%c ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
	destroyStack(s);
	free(s);

	Queue q;
	initQueue(&q);
	enqueue(&q, 6);
	enqueue(&q, 1);
	enqueue(&q, 5);
	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 1);
	enqueue(&q, 9);
	printf("\nBefore Cut and Replace:\n");
	intNode* k = q.head;
	while (k != NULL)
	{
		printf("%d ", k->data);
		k = k->next;
	}
	cutAndReplace(&q);
	printf("\nAfter Cut and Replace:\n");
	k = q.head;
	while (k != NULL)
	{
		printf("%d ", k->data);
		k = k->next;
	}
	printf("\nBefore rotate:\n");
	k = q.head;
	while (k != NULL)
	{
		printf("%d ", k->data);
		k = k->next;
	}
	rotateQueue(&q);
	printf("\nAfter Rotate:\n");
	k = q.head;
	while (k != NULL)
	{
		printf("%d ", k->data);
		k = k->next;
	}
	printf("\nBefore sorting:\n");
	k = q.head;
	while (k != NULL)
	{
		printf("%d ", k->data);
		k = k->next;
	}
	sortKidsFirst(&q);
	printf("\nAfter sorting:\n");
	k = q.head;
	while (k != NULL)
	{
		printf("%d ", k->data);
		k = k->next;
	}
}