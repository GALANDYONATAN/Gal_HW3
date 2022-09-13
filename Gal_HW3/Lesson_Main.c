#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	char data; // 1B
	int id; // 4B
	struct Node* next; // 4B
}Node1;

Node1* create_new_list(char data, int id);
Node1* add_new_Node1_to_start_of_list(Node1* head, char data, int id);

void main()
{
	Node1* ptr = NULL;
	ptr = add_new_Node1_to_start_of_list(NULL, 'a', 30);
	ptr = add_new_Node1_to_start_of_list(ptr, 'b', 50);
	ptr = add_new_Node1_to_start_of_list(ptr, 'c', 10);
	ptr = add_new_Node1_to_start_of_list(ptr, 'd', 20);
	ptr = add_new_Node1_to_start_of_list(ptr, 'e', 30);
	ptr = add_new_Node1_to_start_of_list(ptr, 'f', 0);
	ptr = add_new_Node1_to_start_of_list(ptr, 'g', 25);

	Node1* t = ptr;
	while (t != NULL)
	{
		printf("%d\n", t->id);
		t = t->next;
	}
}

Node1* create_new_list(char data, int id)
{
	Node1* t = (Node1*)malloc(1 * sizeof(Node1));
	if (t == NULL)
		return NULL;
	t->data = data;
	t->id = id;
	t->next = NULL;
	return t;
}

Node1* add_new_Node1_to_start_of_list(Node1* head, char data, int id)
{
	Node1* g = create_new_list(data, id);
	if (head != NULL) // the list is empty
	{
		if (g->id > head->id) // if needed to place in start of list
			g->next = head;
		else
		{ 
			// placing in middle of list
			Node1* f = head;
			while (f->next != NULL && f->next->id > g->id)
				f = f->next;
			g->next = f->next;
			f->next = g;
			return head;
		}
	}
	return g;
}