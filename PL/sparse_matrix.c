
#include <stdio.h>
#include <stdlib.h>
#define pf printf
#define sf scanf
struct sparse
{
	int r,c,val;
};

int input(struct sparse s[10]);
void display(struct sparse s[10],int c);
int add(struct sparse s1[10],struct sparse s2[10],struct sparse s3[20]);
void trans(struct sparse s1[10],struct sparse s2[10]);
void ftrans(struct sparse s1[10],struct sparse s2[10]);

int input(struct sparse s[20])//different functions for get and convert
{
	
	int i,j,row,flag=0,col,count=0,a[5][5];
	int k=1;

	do
	{
		pf("enter number of rows and columns");
		sf("%d%d",&row,&col);

		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
			    printf("\n enter element of[%d][%d]:-",i,j);
				scanf("%d",&a[i][j]);
				if(a[i][j]!=0)
					count++;
		
			}
		}
		/*if(count>(row*col)/2)
		{
			flag=1;
			pf("\nmatrix cant be sparse, enter elements again\n");
		}
		else 
			flag=0;*/
	}while(flag==1);		//end of loop
	

	for(i=0;i<row;i++)
	   	{
	        	for(j=0;j<col;j++)
	      		{
	            		if(a[i][j]!=0)
				{
					s[k].r=i;
					s[k].c=j;
					s[k].val=a[i][j];
					k++;
				}
	       		 }
	   	}
	s[0].r=row;
	s[0].c=col;
	s[0].val=k-1;
	return k-1;	
}

//  convert(int a[][max], strcut sparse s[])

void display(struct sparse s[10],int c)
{
	int i,j;
	printf("\n row\t col\t val\n");

	for(i=0;i<=c;i++)
	{
		printf("%d\t%d\t%d",s[i].r,s[i].c,s[i].val);
		printf("\n");
	}
}

int add(struct sparse s1[10],struct sparse s2[10],struct sparse s3[20])
{
	int i=1,j=1,k=1;
	if(s1[0].r==s2[0].r&&s1[0].c==s2[0].c)
	{
		s3[0].r=s1[0].r;
           	s3[0].c=s1[0].c;
		while(i<=s1[0].val||j<=s2[0].val)
		{
			if(s1[i].r<s2[j].r)
       			{
        		      s3[k].r=s1[i].r;
        		      s3[k].c=s1[i].c;
        		      s3[k].val=s1[i].val;
        		      k++;
        		      i++;
			}
			else if(s1[i].r>s2[j].r)
       			{
        		      s3[k].r=s2[j].r;
        		      s3[k].c=s2[j].c;
        		      s3[k].val=s2[j].val;
        		      k++;
        		      j++;
			}
			else if(s1[i].r==s2[i].r && s1[i].c<s2[j].c)
        		{
            			s3[k].r=s1[i].r;
            			s3[k].c=s1[i].c;
            			s3[k].val=s1[i].val;
           			k++;
            			i++;
			}
			else if(s1[i].r==s2[i].r && s2[j].c<s1[i].c)
        		{
           			s3[k].r=s2[j].r;
            			s3[k].c=s2[j].c;
            			s3[k].val=s2[j].val;
            			k++;
            			j++;
			}
			else if(s1[i].r==s2[j].r && s1[i].c==s2[j].c)
     			{
            			s3[k].r=s1[i].r;
            			s3[k].c=s1[i].c;
            			s3[k].val=s1[i].val+s2[j].val;
            			k++;
            			i++;j++;
        		}
			 
		}   //end of while
	} //end of if
    	s3[0].val=k-1;
	return k-1;
}
void trans(struct sparse s1[10],struct sparse s2[10])
{
	int i,j,row,col;
	s2[0].r=s1[0].c;
	s2[0].c=s1[0].r;
	s2[0].val=s1[0].val;
	int k=1;
	if(s1[0].val>0)
	{
		for(i=0;i<s1[0].c;i++)
		{
			for(j=1;j<=s1[0].val;j++)
			{
				if(s1[j].c==i)
				{
					s2[k].r=s1[j].c;
					s2[k].c=s1[j].r;
					s2[k].val=s1[j].val;
					k++;
				}
			}	
		}
	}
}

void ftrans(struct sparse s1[10],struct sparse s2[10])
{
	
	int i,j,row,col,a[10],b[10];
	s2[0].r=s1[0].c;
	s2[0].c=s1[0].r;
	s2[0].val=s1[0].val;
	for(i=0;i<s1[0].c/*no of colms*/;i++)
	{
		a[i]=0;
	}
	
	for(i=1;i<=s1[0].val;i++)			//a for column store
	{
		a[s1[i].c]++;
	}
	
	b[0]=1;
	
	for(i=1; i<=s1[0].c ;i++)				//b for count store
	{
		b[i]=b[i-1]+a[i-1];
	}
	
	for(i=1;i<=s1[0].val;i++)
	{
		s2[b[s1[i].c]].r=s1[i].c;
		s2[b[s1[i].c]].c=s1[i].r;
		s2[b[s1[i].c]].val=s1[i].val;
		b[s1[i].c]++;
	}
}


int main()
{
	int a[10][10],b[10][10],c[10][10];
	int row,col,val3,c1,c2,choice,z=0;
	struct sparse s1[10],s2[10],s3[20],s4[10];
	
	pf("\nfor matrix 1\n");
	c1=input(s1);
	pf("\nnfor matrix 2\n");
	c2=input(s2);

	do 
	{	
		pf("\n***************MENU**************\n");
		pf("1.change input\n2.display\n3.addition\n4.transpose\n5.fast transpose\n6.exit");
		pf("\n*********************************\n");
		pf("\n\n\tEnter your choice:");
		sf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				c1=input(s1);
				c2=input(s2);
				break;
			case 2:
				display(s1,c1);
				display(s2,c2);
				break;
			case 3:
				val3=add(s1,s2,s3);
				display(s3,val3);
				break;
			case 4:
				pf("transpose of mat 1 is");	
				trans(s1,s4);
				display(s4,c1);
				pf("transpose of mat 2 is");
				trans(s2,s4);
				display(s4,c2);
				break;
			case 5:
				pf("fast transpose of mat 1 is");	
				ftrans(s1,s4);
				display(s4,c1);
				pf("fast transpose of mat 2 is");
				ftrans(s2,s4);
				display(s4,c2);;
				break;
			case 6:
				exit(0);
		}
	}while(1);
			
	return 0;
}

