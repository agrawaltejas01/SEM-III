/*

ASSIGNMENT          :  4
ROLL NUMBER         : 2010
BATCH               : E-10
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct date
{
    int d;
    int m;
    int y;
}Date;

typedef struct students
{
    char name[20];
    int roll;
    char dept[5];
    char ph_no[11];
    Date bdate;
    int marks[5]; 
    float avg;
    int flag;
}stud;

int getnumber(char p[])             //phone number validation
{
    int i=0;
    do
       { 
         int len=0;
            printf("Enter phone number\n");
            scanf("%s",p);

           while(p[i]!='\0' && ( isdigit(p[i]) ) )
           {
                i++;                
            }
            
            if(p[i]=='\0')
                break;
            
            else
                printf("Numbers cannot have alphabets\n");
        }
        while(1);
        return i;
}
    
void getname(char p[])          //name validation
{
    do
       { 
         int i=0,len=0;
            printf("Enter name\n");
            scanf("%s",p);

           while(p[i]!='\0' && (isalpha(p[i])))
           {
                i++;
            }
            
            if(p[i]=='\0')
                break;
            
            else
                printf("Name cannot have numbers\n");
        }
        while(1);
}
            
            
          


void insert(stud s[],int n,int *e)      //create && add
{
    static int r=2001;
    for(int i=*e;i<n+*e;i++)
    {
        s[i].roll=r++;
        
        s[i].flag=1;
        
        getname(s[i].name);
        
        printf("Enter department\n");
        scanf("%s",s[i].dept);
        
         int len;
           len= getnumber(s[i].ph_no);
        
        while(len!=10)
        {
            printf("Number must have 10 digits\n");
            len=getnumber(s[i].ph_no);
        }
        
        
        printf("Enter date of birth in dd/mm/yyyy format\n");
        scanf("%d/%d/%d",&s[i].bdate.d,&s[i].bdate.m,&s[i].bdate.y);
        
        while(s[i].bdate.d<1 || s[i].bdate.d>30 || s[i].bdate.m<1 || s[i].bdate.m>12 || s[i].bdate.y<1985 || s[i].bdate.d>2000)
        {
            printf("Date of birth is invalid\n Enter date of birth again\n");
            scanf("%d/%d/%d",&s[i].bdate.d,&s[i].bdate.m,&s[i].bdate.y);
        }
        
        s[i].avg=0;
        
        for(int j=0;j<5;j++)
        {
            printf("Enter marks of subject %d: ",j+1);
            scanf("%d",&s[i].marks[j]);
            
            s[i].avg=s[i].avg+s[i].marks[j];
        }
    }
    
    *e=n+*e;
}


void search(stud s[],int r,int e)       //search
{
    int i;
    for(i=0;i<e;i++)
    {
        if(s[i].roll==r && s[i].flag==1)        
        {
            printf("Found\n");
                        
             printf("%10s \t%5d \t%5s \t%12s \t%2d/%2d/%4d \t%2f\n ",s[i].name,s[i].roll,s[i].dept,s[i].ph_no,s[i].bdate.d,s[i].bdate.m,s[i].bdate.y,s[i].avg);             
             break;
         }
     }
     
     if(i==e)
        printf("NO such Record in database\n");
}

void update(stud s[],int r)         //update
{
        int i=r-2001;
        
        if(s[i].flag==1)
        {
           // s[i].roll=r++;
            
            getname(s[i].name);
            
            printf("Enter department\n");
            scanf("%s",s[i].dept);
            
             int len;
               len= getnumber(s[i].ph_no);
            
            while(len!=10)
            {
                printf("Number must have 10 digits\n");
                len=getnumber(s[i].ph_no);
            }
            
            
            printf("Enter date of birth in dd/mm/yyyy format\n");
            scanf("%d/%d/%d",&s[i].bdate.d,&s[i].bdate.m,&s[i].bdate.y);
            
            //while(s[i].bdate.d
            
            s[i].avg=0;
            
            for(int j=0;j<5;j++)
            {
                printf("Enter marks of subject %d: ",j+1);
                scanf("%d",&s[i].marks[j]);
                
                s[i].avg=s[i].avg+s[i].marks[j];
            }
        }
        
        else
        printf("NO such Record in database\n");
    
}

void delete(stud s[],int r,int e)           //delete
{
    for(int i=0;i<e;i++)
    {
        if(s[i].roll==r)
         {
             s[i].flag=0;
               printf("Deleted\n");
             //printf("%10s \t%5d \t%5s \t%12s \t%2d/%2d/%4d \t%2f\n ",s[i].name,s[i].roll,s[i].dept,s[i].ph_no,s[i].bdate.d,s[i].bdate.m,s[i].bdate.y,s[i].avg);
        }
    }
} 

  

void print(stud s[],int e)
{
    for(int i=0;i<e;i++)
    {
        if(s[i].flag==1)
        {
            printf("%10s \t%5d \t%5s \t%12s \t%2d/%2d/%4d \t%2f\n ",s[i].name,s[i].roll,s[i].dept,s[i].ph_no,s[i].bdate.d,s[i].bdate.m,s[i].bdate.y,s[i].avg);
        }
    }
}

int main()
{
   stud s[15];
    
    int e=0;
    int n,m;
   
   
   do
   {
        int ch;
        
        printf("Menu\n");
      printf("\t1.Add\n\t2.Display database\n\t3.Search\n\t4.Modify\n\t5.Delete\n\t6.exit\n");
        scanf("%d",&ch);
        
        
        switch(ch)
        {
           case 1:                 //create
            {
                printf("Enter number of records you want to insert\n");
                scanf("%d",&n);
                insert(s,n,&e);
                
                //printf("%10s \t%5s %5s \t%12s \t%8s \t%2s\n ","NAME","ROLL NO.","DEPT","PHONE","DOB","AVG");
                //print(s,e);
                
                break;
            }
            
            case 2:             //print
            { 
                    printf("%10s \t%5s %5s \t%12s \t%8s \t%2s\n ","NAME","ROLL NO.","DEPT","PHONE","DOB","AVG");
                    print(s,e);               
                    break;
            }

            
            case 3:                 //search
            {
                printf("Enter roll number to be searched\n");
                scanf("%d",&n);
                search(s,n,e);
                break;
            } 
               
            
            case 4:                     //modify
            {
                int r;
                printf("Enter roll number of student of which you want to modify\n");
                scanf("%d",&r);
                
                update(s,r);
                break;
            }
            
            case 5:                     //delete
            {
                int r;
                printf("Enter roll number of student of which you want to delete\n");
                scanf("%d",&r);
                
                delete(s,r,e);
                break;
            }
            
            case 6:                 //exit
            {
                exit(0);
                break;
            }
        }
   }while(1);
   
   return 0;
}

