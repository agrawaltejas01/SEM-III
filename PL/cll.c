/*

ASSIGNMENT          :  10
NAME                : TEJAS SANJIV AGRAWAL
ROLL NUMBER         : 2002
BATCH               : E-10
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
	
	float cof;
	int power;
	struct Node *next;
}Node;

Node* create_node (int , float);//function for creating Node
Node* create_polynomial ();//function for creating Polynomial
void display_polynomial (Node* );//function for displaying Polynomial
void evaluate (Node* );//function for evaluating polynomial
void add_polynomial (Node*, Node*);//function for adding polynomial
void mul_polynomial (Node*, Node*);//function for multiplying polynomial
void display_polynomial (Node *);//function for displaying polynomial

int main () {
	
	Node *rear1, *rear2, *add, *mul;
	int choice,c;

	printf ("\n****** CREATING POLYNOMIAL ******\n");
	printf ("\nEnter Polynomial A : ");
	rear1 = create_polynomial();
	printf ("\nPolynomial A = ");
	display_polynomial (rear1);
	printf ("\n\nEnter Polynomial 2 : ");
	rear2 = create_polynomial();
	printf ("\nPolynomial 2 = ");
	display_polynomial (rear2);
	printf ("\n********************************\n");
	
	do {
		
		printf ("\n\nEnter 0 To Exit ");
		printf ("\nEnter 1 To Update Polynomial A ");
		printf ("\nEnter 2 To Update Polynomial B ");
		printf ("\nEnter 3 To Display Polynomial A and B");
		printf ("\nEnter 4 To Evaluate Polynomial ");
		printf ("\nEnter 5 To Add Polynomial A and B (A+B) ");
		printf ("\nEnter 6 To Multiply Polynomial ");
		printf ("\nEnter Your Choice : ");
		scanf ("%d", &choice);
		
		switch (choice) {
			
			case 0 : break;
			
			case 1 : printf ("\n**********POLYNOMIAL A**********\n");
					 rear1 = create_polynomial();
					 printf ("\n********************************\n");
					 break;
					 
			case 2 : printf ("\n**********POLYNOMIAL B**********\n");
					 rear2 = create_polynomial();
					 printf ("\n********************************\n");
					 break;
					 
			case 3 : printf ("\n**************************************\n");
					 printf ("\nPolynomial A = ");
					 display_polynomial (rear1);
					 printf ("\n\nPolynomial B = ");
					 display_polynomial (rear2);
					 printf ("\n**************************************\n");
					 break;
			
			case 4 : printf ("\n**********EVALUATING POLYNOMIAL**********\n");	
					 printf ("\nEnter '1' To Evaluate Polynomial A or '2' To Evaluate Polynomial B : ");
					 scanf ("%d", &c);
					 if (c==1) evaluate (rear1);
					 else evaluate (rear2);
					 printf ("\n*****************************************\n");
					 break;
					 
			case 5 : printf ("\n**********ADDING POLYNOMIAL**********\n");
					 printf ("\nF(A) + F(B) = ");
					 add_polynomial (rear1, rear2);
					 printf ("\n*************************************\n");		
					 break;
					 
			case 6 : printf ("\n**********MULTIPLY POLYNOMIAL**********\n");
					 printf ("\nF(A) * F(B) = ");
					 mul_polynomial (rear1, rear2);
					 printf ("\n*************************************\n");		
					 break;
					 
			default : printf ("\nPlease Enter A Valid Choice ");
					  break;
					  
		}
		
	}while (choice!=0);
	
	return 0;
}//end of main

Node* create_node (int power, float cof) {

	Node *p;
	p = (Node *) malloc (sizeof(Node));
	p->power = power;
	p->cof = cof;
	p->next = NULL;
	return p;
}//end of function


Node* create_polynomial () {

	int i,n;
	float cof;
	Node *previous, *p, *head;

	printf ("\nEnter The Degree Of Polunomial : ");
	scanf ("%d", &n);
	printf ("\nEnter Coefficient For Power %d : ", n);
	scanf ("%f", &cof);
	head = create_node (n, cof);
	previous = head;
	for (i=n-1;i>=0;i--) {
		
		printf ("Enter Coefficient For Power %d : ", i);
		scanf ("%f", &cof);
		p = create_node (i, cof);
		previous-> next = p;
		previous = p;
	}
	previous->next = head;
	return previous;
}//end of function


void display_polynomial (Node *rear) {

	Node *p;
	
	p = rear->next;
	printf ("\nPower Coefficient\n");
	do {

		printf ("%-6d %-12.3f\n",  p->power, p->cof);
		p = p->next;
		
	}while (p != rear->next);
	
	display_polynomial1 (rear);

}//end of function


void display_polynomial1 (Node *rear) {

	Node *p;
	
	p = rear->next;
	printf ("\n");
	do {

		printf ("%+0.2f X^%d ",p->cof, p->power);
		p = p->next;
		
	}while (p != rear->next);

	printf ("\n");
}//end of function


void evaluate (Node *rear) {
	
	float x,value = 0;
	Node *p;
	p = rear->next;
	
	printf ("\nEnter The Value of X : ");
	scanf ("%f", &x);
	
	do {
		value = value + (p->cof * pow(x, p->power));
		p = p->next;
	}while (p != rear->next);
	
	printf ("Value Of Polynomial At X = %0.3f is = %0.3f \n", x, value);
}//end of function


void add_polynomial (Node *rear1, Node *rear2) {
	
	Node *p, *head, *previous, *p1, *p2;
	int flag=0;
	
	if (rear1->next->power >= rear2->next->power) {
		p1 = rear1->next;
		p2 = rear2->next;
	}
	else {
		p1 = rear2->next;
		p2 = rear1->next;
		
		previous = rear2;
		rear2 = rear1;
		rear1 = previous;
	}
	
	do {
			
			if (p1->power == p2->power) 
			{
				if (flag==0) 
				{
					p = create_node (p1->power, (p1->cof+p2->cof));
					head=p; 
					previous=p;
					flag++;
					p1 = p1->next;
					p2 = p2->next;
				}
				
				else 
				{
					p = create_node (p1->power, (p1->cof+p2->cof));
					previous->next = p; 
					previous=p;
					p1 = p1->next;
					p2 = p2->next;
				}
			}
			
			else 
			{
				
				if (p1->power > p2->power) {
					if (flag==0)
					 {
						p = create_node (p1->power, p1->cof);
						head=p; previous=p; flag++;
						p1 = p1->next;
					}
					
					else 
					{
						p = create_node (p1->power, p1->cof);
						previous->next = p; previous = p;
						p1 = p1->next;
					}
				}
				
				else 
				{
					p = create_node (p2->power, p2->cof);
					previous->next = p; previous=p;
					p2 = p2->next;
				}
			}
	}while ( (p1!=rear1->next) || (p2!=rear2->next) );
	
	previous->next = head;
	display_polynomial (previous);	
}//end of function


void mul_polynomial (Node *rear1, Node *rear2) {
	
	Node *p, *head, *previous, *p1, *p2;
	int flag=0,ind;
	p1 = rear1->next;
	p2 = rear2->next;
	
	do {
		
		do {
			if (flag==0) {
				p = create_node ( (p1->power+p2->power), (p1->cof*p2->cof));
				head = p; previous = p; flag++;
				p2 = p2->next;
			}
			else {
				p = create_node ( (p1->power+p2->power), (p1->cof*p2->cof) );
				previous->next = p;
				previous = p;
				p2 = p2->next;
			}
		}while (p2!=rear2->next);
		
		p1 = p1->next;
	}while (p1!=rear1->next);
	
	previous->next = head;
	
		p1 = previous;
		p2 = previous;
		flag=0;
		p1 = p1->next;
		ind = p1->power;
		do {
			
			do {
				
				if (p1->power == ind) {
					
					if (flag==0) {
						p = create_node (p1->power, p1->cof);
						previous = p;head = p;flag++;
						p1=p1->next;
					}
					
					else if (flag==2) 
					{
						p = create_node (p1->power, p1->cof);
						previous->next = p;
						previous = p;
						p1 = p1->next;
						flag++; 
					}
					else 
					{
						p->cof = p1->cof + p->cof;
						p1 = p1->next;
					}
				}
				else p1 = p1->next;
				
			}while (p1!=p2->next);
 		
		ind--;
		flag=2;	
				
		}while (ind>=0);
		
		previous->next = head;
		display_polynomial (previous);
	
}//end of function
