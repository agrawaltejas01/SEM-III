/*
    ASSIGNMENT : 11
    NAME : TEJAS SANJIV AGRAWAL
    ROLL NO : 2002
    BATCH : E-10
*/


#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    char data;
    struct node *left;
    struct node *right;
}node;

node *create(int n,char arr[])
{
    node *head,*p,*new;
    
    //printf("Enter element\n");
    
    head=(node *)malloc(sizeof(node));
    head->left=NULL;
    head->right=NULL;
    
    //scanf("%d",&head->data);
    
    head->data=arr[0];
    
    p=head;
    
    for(int i=1;i<n;i++)
    {
        new=(node *)malloc(sizeof(node));
        new->left=p;
        p->right=new;
        
        //scanf("%d",&new->data);
        new->data=arr[i];
        p=p->right;
        
        new->right=NULL;
    }
    
    return head;
}

void display_forward(node *head)
{
    node *p;
    p=head;
    
    while(p!= NULL) 
    {
        printf("%c",p->data);
        p=p->right;
    }
    
    printf("\n");
}

node *insert(node *head,int pos,char val,int n)
{
    node *new,*p;
    p=head;
    
    new=(node *)malloc(sizeof(node));
    
    new->data=val;
    
    new->right=NULL;
    new->left=NULL;
    
    if(pos==0)
    {
        new->right=p;
        p->left=new;
        
        return new;
    }
    
    else if(pos==-1 || pos>n)
    {
        node *temp;
        temp=head;
        
        while(temp->right != NULL)
            temp=temp->right;
        
        temp->right=new;
        new->left=temp;
        
        return head;
    }
    
    else
    {
        node *temp;
        temp=head;
        
        while(temp->right != NULL && --pos)
            temp=temp->right;
        
        new->left=temp;
        (temp->right)->left=new;
        
        new->right=temp->right;   
        
        temp->right=new;
        
        return head;
    }     
}

void display_backward(node *p)
{
    if(p==NULL)
        return ;
    
    display_backward(p->right);
    
    printf("%c",p->data);

    
}

node *delete(node *head,char val)
{
    node *temp,*p;
    
    temp=head;
    
    while(temp != NULL && temp->data != val)
        temp=temp->right;
    
    if(temp == NULL)
        return NULL;
    
     if(temp->data == val)
    {
        if(temp->left == NULL)          //if 1st node
         {
            temp=temp->right;    
            
            temp->left=NULL;
            
            return temp;
        }
        
        else if(temp->right == NULL)        //last node
        {
            p=temp->left;
            
            //p->left=NULL;
            
            p->right=NULL;
            
            return head;
        }
        
        else
        {
            (temp->right)->left = temp->left;
            
            (temp->left)->right = temp->right;
            
            return head;
        } 
    }
}   

int main()
{   
      node *p;
   
   char string[20];
   
   printf("Enter string\n");
   scanf("%s",string);
      
   p=create(strlen(string),string);
   
   printf("*************** LINKED LIST CREATED ******************\n\n");
   
   printf("Give string was : ");
   display_forward(p);
   
   do
   {
        int ch;
        printf("----------------MENU--------------\n\n");
        
        printf("\t1.INSERT\n\t2.DELETE\n\t3.DISPLAY\n\t4.DISPLAY REVERSE\n\t5.RE-ENTER\n\t6.EXIT\n");
        printf("----------------------------------\n\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
            {
                   printf("INSERT\n");
                   
                   int pos;
                   
                   char val;
                   
                printf("Enter pos and val (0==beg -1==end)\n");
                   scanf("%d %c",&pos,&val);
                   
                   node *new;
                   new=insert(p,pos,val,strlen(string));
                   
                   p=new;
                   printf("**********UPDATED LIST IS*************\n\t ");
                   display_forward(p);
                   break;
            }
               
             case 4:
             {     
                printf("LIST REVERDED IS : "); 
                   display_backward(p);
                   printf("\n");
                   
                   break;
             } 
             
             case 2:
             {     
                   printf("Delete\n");
                   
                   char val;
                   
                   printf("Enter value you want to delete\n");
                   scanf("\n%c",&val);                              //caution
                   
                   node *new;
                   new=delete(p,val);
                   
                   if(new == NULL)
                    printf("Value does not exists\n");
                   
                   else
                    p=new;
                   
                   printf("**********UPDATED LIST IS*************\n\t ");
                   display_forward(p);
                   printf("\n");
                   
                   break;
           }
           
               case 3:
               {
                    printf("******YOUR LIST IS**********\n\t");
                     display_forward(p);
                     break;
             }
             
             case 5:    main();
             
             case 6: exit(0);
             
         
        }
   
   }
   while(1);
   
   return 0;
}

