
/*

ASSIGNMENT          :  9
NAME                : TEJAS SANJIV AGRAWAL
ROLL NUMBER         : 2002
BATCH               : E-10
*/

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* link;
}node;

node * create(int n)
{
    node *head,*p;
    
    head=(node *)malloc(sizeof(node));
    head->link=NULL;
    
    scanf("%d",&(head->data));
    
    p=head;
    
    int i;
    for( i=1;i<n;i++)
    {
        p->link=(node *)malloc(sizeof(node));
        p=p->link;
        scanf("%d",&(p->data));
        p->link=NULL;
    }
    
    return head;
}

node * delete(node *head,int pos)
{
    if(pos==0)
        head=head->link;
    
    else if(pos==-1)
    {
        node *temp,*q;
        
        q=head;
        
        while(q->link!=NULL)
        {
            temp=q;
            q=q->link;
        }
        
        temp->link=NULL;
    }
    
    else
    {
        node *temp,*q;
        
        q=head;
        
        while(q->link!=NULL && pos--)
        {
            temp=q;
            q=q->link;
        }
        
        temp->link=q->link;
    }
    
    return head;
}


void display(node * p)
{
    while(p!= NULL)
    {
        printf("%d ",p->data);
        p=p->link;
    }
    
    printf("\n");
}

void print_reverse(node *p)
{
    if(p==NULL)
        return ;    
    
    print_reverse(p->link);
    printf("%d ",p->data);
    
    //printf("\n");
}

node * reverse( node * ptr )
{
    node * temp;
    node * previous = NULL;
    while(ptr != NULL)
     {
        temp = ptr->link; 
          
        ptr->link = previous;
        previous = ptr;
        
        ptr = temp;
    }
    return previous;
} 

node * add( node * head,int pos,int val,int n)
{
    node *p,*q;
    
    p=(node *)malloc(sizeof(node));
    p->data=val;
    
    q=head;
    
    if(pos==0)
    {
        p->link=head;
        return p;
    }
    
    if(pos==-1 || pos>n)
    {
        while(q->link!=NULL)
            q=q->link;
        
        q->link=p;
        p->link=NULL;
        
        return head;
    }
    
    else
    {
        while(q!=NULL && --pos)
            q=q->link;
        
        p->link=q->link;
        q->link=p;
        
        return head;    
    }
} 
        
int main()
{
        printf("CREATE A LINKED LIST TO GET STARTED\n");
        
        int n,pos,ch,val;
        printf("Length of linked is?\n");
        scanf("%d",&n);
        
        node *p;
        p=NULL;
        
        p=create(n);
        printf("Created linked list is\n\n");
        display(p);
    do
    {    
        
        printf("----------MENU----------\n");
        printf("\t1.ADD\n\t2.DELETE\n\t3.DISPLAY REVERSE\n\t4.REVERSE\n\t5.EXIT\n\n");
        printf("ENTER CHOICE : ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
            {
                node *new;
                printf("Enter position you want to add (0=begining -1=end) \n");
                
                scanf("%d %d",&pos,&val);                    
                new=add(p,pos,val,n);
                
                p=new;
                
                
                display(p);
                break;
            }
            
            case 2:
            {
                printf("Enter position you want to delete (0=begining -1=end) \n");
                scanf("%d",&pos);
                
                node *new;
                
                new=delete(p,pos);
                
                p=new;
                
                display(p);
                
                break;
            }
            
            case 3:
            {
                printf("\nREVERSED LIST IS \n\t\n");
                print_reverse(p);
                
                printf("\n");
                break;
            }
            
            case 4:
            {
                
                node *new;
                 printf("\nNEW LIST IS \n\t\n");
                new=reverse(p);
                
                p=new;
                
                display(p);
                
                break;
            }
            
            
            case 5:
                exit(0);
        }
    }
    while(1);
    
    return 0;
}

