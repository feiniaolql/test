#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_LEN		20

typedef struct node {
	char name[NAME_LEN];	
	struct node *next;
} t_node;


t_node *create_nodes(int number)
{
	int i;
	t_node *head, *pre, *post, *curr;
	char str[NAME_LEN];

	head = (t_node *) malloc(sizeof(t_node));
	head->name[0] = '\0';

	head->next = NULL;
	pre = head;

	for (i = 0; i < number; i++) {
		curr = (t_node *) malloc(sizeof(t_node));				
		sprintf(str, "%d", i);
		strcpy(curr->name, str);	
		curr->next = NULL;
		
		pre->next = curr;
		pre = curr;
	}

	return head;
}

void insert_node(t_node *p, int num, char *str)
{
	int i;
	t_node *curr, *insert, *tmp;
	
	curr = p->next;
	for (i = 0; i < num; i++)
		curr = curr->next;		

	insert = (t_node *) malloc(sizeof(t_node));
	tmp = curr->next;
	curr->next = insert;
	strcpy(insert->name, str);
	insert->next = tmp;
}

int remove_node(t_node *p, int num)
{
	int i;
	t_node *curr, *tmp;

	curr = p;
	for (i = 0; i < num; i++) {	
		curr = curr->next;
		if (curr->next == NULL) {
			printf("No such node.\n");
			return 1;
		}
	}

	tmp = curr->next;
	curr->next = tmp->next; 

	free (tmp);
}

void output_nodes(t_node *p)
{
	t_node *curr;
	curr = p;

	while (curr->next != NULL) {
		curr = curr->next;
		printf("%s ", curr->name);
	}
	printf("\n");
}


int main(int argc, char **argv)
{
	t_node *head;
	
	head = create_nodes(10);
	output_nodes(head);
	//insert_node(head, 4, "test");
	//output_nodes(head);
	remove_node(head, 4);
	remove_node(head, 11);
	output_nodes(head);

	return 0;
}
