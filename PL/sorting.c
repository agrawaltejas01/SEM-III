/*

ASSIGNMENT          :  6
NAME                : TEJAS SANJIV AGRAWAL
ROLL NUMBER         : 2002
BATCH               : E-10
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct students
{
    int roll;
    char name[20];
    float per;
} stud;

void add(stud s[],int n,int e)
{    
    
    for(int i=e;i<n+e;i++)
    {
        printf("Student %d\n\n",i+1);
        
        printf("Enter Roll no : ");
        scanf("%d",&s[i].roll);
        printf("\n");
        
        printf("Enter Name : ");
        scanf("%s",s[i].name);
        printf("\n");
        
        printf("Enter Percentage : ");
        scanf("%f",&s[i].per);
        printf("\n");
    }
}

void print(stud s[],int e)
{

    printf("----------------------------------------------------------------------------\n");
    printf("%5s \t%10s \t%5s\n","ROLL","NAME","PERCENT");        
    printf("-----------------------------------------------------------------------------\n");
    
    for(int i=0;i<e;i++)
    {
        printf("%5d \t%10s \t%5f\n",s[i].roll,s[i].name,s[i].per);
    }
    
    printf("\n");
}

int bubble(stud s[],int e)
{
    int count=0;
    for(int i=0;i<e-1;i++)
    {
        int flag=0;
        for(int j=0;j<e-i-1;j++)
        {
            if(s[j].roll>s[j+1].roll)
            {
                stud temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
                flag=1;
                
            }
        
        }
        
        count++;
        
        if(!flag)
            break;
        
    }
    
    return count;
}

int selection_sort(stud s[],int e)
{
    char copy[100];
    int count=0;
    
    for(int i=0;i<e;i++)
    {
        int j=i;
        strcpy(copy,s[i].name);
        
       for(int k=i+1;k<e;k++)
       {
            if(strcmp(copy,s[k].name) > 0)
            {
                strcpy(copy,s[k].name); 
                
                j=k;
            }
        } 
        
        if(j!=i)
        {
            stud temp=s[j];
                s[j]=s[i];
                s[i]=temp;
        }
        
         count++;
    }    

    return count;
}
  


void search_rec(stud s[],int end,const int beg,const int mid,int r)
{
   
   if(beg<=end)
   {
        if(r==s[mid].roll)
        {
                printf("------------------------------------------------------------------------\n");
                printf("%5s \t%10s \t%5s\n","ROLL","NAME","PERCENT");        
                printf("-------------------------------------------------------------------------\n"); 
                
                printf("%5d \t%10s \t%5f\n",s[mid].roll,s[mid].name,s[mid].per);
         }
         
         else if(r<s[mid].roll)
            search_rec(s,mid,beg,mid/2,r);
        
        else if(r>s[mid].roll)
            search_rec(s,end,mid,end/2,r);
    }
    
    else
        printf("\n!!!!! NO SUCH ENTRY IN DATABASE !!!!!\n");
}
               
void search(stud s[],int e,int r)
{
    int end=e-1;
    int beg=0;
    
     int flag=0;  
    
    while( beg<=end)
    {
        int mid=(beg+end)/2;
        
        if(r==s[mid].roll)
        {
            flag=1;
            printf("-----------------------------------------------------------------------------\n");
            printf("%5s \t%10s \t%5s\n","ROLL","NAME","PERCENT");        
            printf("------------------------------------------------------------------------------\n"); 
            
            printf("%5d \t%10s \t%5f\n",s[mid].roll,s[mid].name,s[mid].per);
            break;
        }
        
        else if(r<s[mid].roll)
        {
            beg=0;
            end=mid-1;
            mid=(beg+end)/2;
        }
        
        else if(r>s[mid].roll)
        {
            beg=mid+1;
            end=e-1;
            mid=(beg+end)/2;
        }
    }
    
    if(flag==0)
        printf("\n!!!!! NO SUCH ENTRY IN DATABASE !!!!!\n");
}

int main()
{
    stud s[20];
    
    int e=0,pass_bubble,pass_selection;
    
    int n;
    
    do
    {
        printf("Menu\n\t1.Enter Data\n\t2.Bubble Sort\n\t3.Selection sort\n\t4.Binary search With Recursion\n\t5.Binary search\n\t6.Number of passes\n\t7.Change Input\n\t8.Exit");
        printf("\n\n\tEnter your choice : ");
        
        int ch;
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
            {
                printf("Enter number of records you want to add : ");
                scanf("%d",&n);
                printf("\n");
                
                add(s,n,e);
                e=n+e;
                
                break;
            }
            
            case 2:
            {
               pass_bubble=bubble(s,e);
                print(s,e);
                
                break;
            }
            
            case 3:
            {
                pass_selection=selection_sort(s,e);
                print(s,e);
                
                break;
            }
            
            case 4:
            {
                printf("Enter roll number you want to search : ");
                int r;
                scanf("%d",&r);
                printf("\n");
                
                 pass_bubble=bubble(s,e);
                search_rec(s,e-1,0,e/2,r);
                
                break;
            }
            
            case 5:
            {
                printf("Enter roll number you want to search : ");
                int r;
                scanf("%d",&r);
                printf("\n");
                
                bubble(s,e);
                search(s,e,r);
                break;
            }
            
            case 6:
            {
                printf("Number of passes in bubble sort are : %d\n\n",pass_bubble);
                printf("Number of passes in Selection sort are : %d\n\n",pass_selection);
                
                break;
            }
            
            case 7:
            {
                main();
                break;
            }
            
            case 8:
            {
                exit(0);
            }
            
        }
    }
    while(1);
        
    return 0;
}
                
