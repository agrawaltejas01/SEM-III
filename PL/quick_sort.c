/*

ASSIGNMENT          :  7
ROLL NUMBER         : 2010
BATCH               : E-10
*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


typedef struct
{
    char name[20];
    long long int ph_no;
    int bill_amt;
}data;



void display(data s[],int start,int n,int flag)
{
    if(flag==1)
    {
    	int i;
        for(i=start;i<n;i++)
        {
            
           printf("%12lld \t%10s \t%5d\n",s[i].ph_no,s[i].name,s[i].bill_amt);
       }
       
       printf("\n\n");
   }
}


void getname(char p[])          //name validation
{
    do
       { 
         int i=0,len=0;
            printf("Enter name : ");
            scanf("%s",p);
            printf("\n");

           while(p[i]!='\0' && (isalpha(p[i])))
           {
                i++;
            }
            
            if(p[i]=='\0')
                break;
            
            else
                printf("\nInvalid Name\n\n");
        }
        while(1);
}

//------------------------------------------------------------
void getdata(data s[],int n)
{
	int i;
    for(i=0;i<n;i++)
    {
        getname(s[i].name);
                
        printf("Enter Phonr number : ");
        scanf("%lld",&s[i].ph_no);
        printf("\n");
        
                
        printf("Enter your bill amount : ");
        scanf("%d",&s[i].bill_amt);
        printf("\n");
    }
}

int partition(data a[],int low,int high,int flag)
{
    print(a,low,high,flag);
    
    long long int piv,left,right,temp;
    piv=a[low].ph_no;
    left=low;
    right=high+1;
    
    
    do
    {
               
        do
        {
            left++;
        }   
        while(a[left].ph_no<piv && left<=high);
        
        do
        {
            right--;
        }   
        while(piv<a[right].ph_no);
        
        if(left<right)
        {
        	data temp;
            temp=a[left];
            a[left]=a[right];
            a[right]=temp;
        }
        
    }while(left<right);
    
    a[low]=a[right];
    a[right]=piv;
    
    return(right);
} 

int quick_sort(data a[],int low,int high,int flag)
{
    int j,count=0;
    if(low<high)
    {    
        count++;                       //check
        j=partition(a,low,high,flag);
        
        count += quick_sort(a,low,j-1,flag);
         count += quick_sort(a,j+1,high,flag);
    }
    
    return count;
}
 
int main()
{   int cntr=0; 
    int n,i=1;
    
    data s[50];
    
    FILE *p;
    p=fopen("test.txt","r");
    
    fscanf(p,"%lld %s %d ",&s[0].ph_no,s[0].name,&s[0].bill_amt);
    
    while(!feof(p))
    {
        fscanf(p,"%lld %s %d ",&s[i].ph_no,s[i].name,&s[i].bill_amt);
        i++;
    }
    
    n=i;
    
    print(s,0,n,1);
        do
    {
        int ch;
        printf("\n\n------------------------ MENU ------------------------\n\n");
        printf("\t1.Enter\n\t2.Display\n\t3.Display pivot position\n\t4.Display no of passes\n\t5.exit\n");
        
        printf("Your choice is : ");
        scanf("%d",&ch);
        printf("\n");
        
        switch(ch)
        {
            case 2:
            {
               cntr = quick_sort(s,0,n-1,0);
                
                 printf("------------------------------------------------------------------------\n");
                printf("%12s \t%10s \t%5s\n","PHONE NUMBER","NAME","PERCENT");        
                printf("-------------------------------------------------------------------------\n"); 
                    
                    print(s,0,n,1);         //1=flag
                   break;
           }
           
           case 3:
           {
                cntr = quick_sort(s,0,n-1,1);
                break;
           }
           
           case 4:
           {
                printf("Number of passes done is : %d\n\n",cntr);
                break;
           }
           
           
           case 5:
                    exit(0); 
        }
    
    }
    while(1);
    
    fclose(p);
    
    return 0;
    
}
    

