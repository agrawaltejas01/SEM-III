/*
    ASSIGNMENT : 12
    NAME : TEJAS SANJIV AGRAWAL
    ROLL NO : 2002
    BATCH : E-10
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 4

typedef struct Node
{
	struct Node *next;
	int flag;			//0 indicates data, 1 indicates use of down link
	union
	{	
		char data[MAX];
		struct Node *dlink;
	}u;
}Node;

Node* getnode()
{
	Node* new1 = (Node*)malloc(sizeof(Node));
	new1->next = NULL;
	new1->u.dlink = NULL;	//does it make char to 000\0?
	return new1;
}

Node* Create_GLL(Node* head, char str[])
{
	int i, j;
	Node* temp;

	for(i = 0; str[i] != NULL; )
	{
		if(str[i] == '(' && i == 0)				//executes only once, w/o i == 0 it is again called at second (
		{										// (1( in (1(1.1))
			head = getnode();
			temp = head;
		}
		else									//str[i] should be at ','
		{
			temp->next = getnode();
			temp = temp->next;
		}
		
		i++;
		j = 0;							//don't forget
		
		while(str[i] != ',' && str[i] != '(' && str[i] != ')')
		{
			temp->u.data[j] = str[i];
			i++;
			j++;
		}
		
		temp->u.data[j] = NULL;
		temp->flag = 0;

		if(str[i] == '(')
		{
			temp->next = getnode();
			temp = temp->next;
			temp->flag = 1;

			temp->u.dlink = Create_GLL(NULL, &str[i]);//head of sublist is down linked to node
			//*** &str[i] passes the address of string from the current position, the function will treat it as base address
			//This is a good way to skip passing initial part of string***

			while(str[i] != ')')		//need to traverse till sublist gets over at ')'
				i++;
			i++;						//move to ',' after ')'
		}
		if(str[i] == ')')
			return head;
	}
}

void Display(Node* temp)
{
	static int depth;
	depth++;
	int i;

	if(temp == NULL)
	{
		if(depth == 1)
			printf("List is Empty");
		else
			printf("Sublist is Empty");

	}
	else
		while(temp != NULL)
		{
			if(temp->flag == 0)
			{
				printf("\n");
				for(i = 1; i <= depth; i++)		//for spacing
					printf("  ");
				printf("%s)", temp->u.data);
			}
			else
				Display(temp->u.dlink);

			temp = temp->next;
		}

	depth--;
}
int main(void)
{
	Node* head = NULL;
	char str[51], repeat = 'n';

	do
	{
		printf("\nEnter the book index string to be converted to GLL: ");
		scanf("\n");
		gets(str);

		printf("The book index is: ");
		//head = Create_GLL(head, "(1(1.1,1.2),2)");
		head = Create_GLL(head, str);
		Display(head);

		printf("\nDo you want to try again (y/n): ");
		scanf(" %c", &repeat);
	}while(repeat == 'y');

	return EXIT_SUCCESS;
}



