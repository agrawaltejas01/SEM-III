
/*TITLE- FILE operation
  Name-Sakshi Bihani
  Class SE-10
  Roll no-2009
*/	
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# define max 10
void gname(char name[])
{
	printf("Enter Name");
	scanf("%s",name);
	if(strlen(name)>10)
	{
		printf("Name size should not exceed 10 characters");
		gname(name);
	}
}
void grollno(int *rollno,FILE *fp1,int a,char arr[])
{
	int choice,marks[5]={0,0,0,0,0},flag=0;
	char name[max],phone[11],day[11],month[3],year[5],branch[5],n[max],p[11];
	char ch;
	float avg=0;
	static int roll=2001;
	int ro;
	if(a==0)
	{
	*rollno=roll;
	++roll;
	}
	else if(a==1)
	{
		fp1=fopen(arr,"r");
		if(fp1!=NULL)
		{

			fscanf(fp1, "%d%s%s%d%d%d%d%d%f%s%s",&ro,name,day,&marks[0],
					&marks[1],&marks[2],&marks[3],&marks[4],&avg,branch,phone);
			while(!feof(fp1))
			{
				fscanf(fp1, "%d%s%s%d%d%d%d%d%f%s%s",&ro,name,day,&marks[0],
						&marks[1],&marks[2],&marks[3],&marks[4],&avg,branch,phone);

			}
			*rollno=ro+1;
			fclose(fp1);
		}
		else
			exit(0);
	}
}
void gphone(char phone[11])
{
	printf("enter phone no");
	scanf("%s",phone);
	int len=strlen(phone);
	int j=0;
	for(j=0;j<len;j++)
	{
		if(!isdigit(phone[j]) || len!=10)
		{
			printf("Re");
			gphone(phone);
		}
	}
}
void gdate(char day[3], char month[3],char year[5])
{
	printf("Enter day of birth");
	scanf("%s",day);
	day[3]='\0';
	printf("Enter month");
	scanf("%s",month);
	printf("Enter year");
	scanf("%s",year);

}
void gmarks(int marks[],float *avg)
{
	int i;
	*avg=0;
	for(i=0;i<5;i++)
	{
		printf("Enter marks");
		scanf("%d",&marks[i]);
		if(marks[i]<=0 && marks[i]>100)
		{
			printf("Mark should be in the range 1-100");
			--i;
		}
		else
		{
			*avg=*avg+marks[i];
		}
	}
	*avg=*avg/5.0;
}
void gbranch(char branch[])
{
	int choice;
	printf("Branch\nEnter\n1 for IT\n2 for Comp\n3 for E&TC");
	scanf("%d",&choice);
	if(choice==1)
	{
		strcpy(branch,"IT");

	}
	else if(choice==2)
	{
		strcpy(branch,"Comp");
	}
	else if(choice==3)
	{
		strcpy(branch,"E&TC");
	}
	else
	{
		printf("enter only 1,2 or 3");
		gbranch(branch);
	}
}
void create(FILE *fp1,char arr[])
{

	int len;
	printf("Enter name of file in which you want to store data");
	scanf("%s",arr);
	len=strlen(arr);
	if(len>10)
	{
		printf("File name should not exceed 10 characters");
		create(fp1,arr);
	}
	else
	{
		arr[len]='\0';
		fp1=fopen(arr,"a");
		printf("File opened successfully\n");
		fclose(fp1);
	}
}
void add(FILE *fp1,char arr[],int a)
{

	int len,rollno,num,i=1,marks[5];
	char name[max],phone[11],day[3],month[3],year[5],branch[5];
	float avg;
	printf("Enter no of entries you want to enter");
	scanf("%d",&num);
	while(i<=num)
	{
		gname(name);
		grollno(&rollno,fp1,a,arr);
		gphone(phone);
		gdate(day,month,year);
		gmarks(marks,&avg);
		gbranch(branch);
		fp1=fopen(arr,"a");
		fprintf(fp1,"%d\t\t%s\t\t%s-%s-%s\t\t%d %d %d %d %d\t%f\t\t%s\t\t%s\n",rollno,
				name,day,month,year,marks[0],marks[1],marks[2],marks[3],marks[4],avg,branch,
				phone);
		++i;
		fclose(fp1);
	}

}

void searchdata(FILE *fp1,char arr[max])
{
	int choice,roll,rollno,marks[5]={0,0,0,0,0},flag=0;
	char name[max],phone[11],day[11],month[3],year[5],branch[5],n[max],p[11];
	char ch;
	float avg=0;
	fp1=fopen(arr,"r");
	if(fp1!=NULL)
	{
		printf("Search using\n1 rollno\n2 name\n3 phone number");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1: printf("enter rollno");
				scanf("%d",&roll);
				fscanf(fp1, "%d%s%s%d%d%d%d%d%f%s%s",&rollno,name,day,&marks[0],
						&marks[1],&marks[2],&marks[3],&marks[4],&avg,branch,phone);
				while(!feof(fp1))
				{
					if(roll==rollno)
					{
						printf("Record Found\n");
						printf("%d\t\t%s\t\t%s\t\t%d %d %d %d %d\t%f\t\t%s\t\t%s\n",rollno,
								name,day,marks[0],marks[1],marks[2],marks[3],marks[4],avg,
								branch,phone);
						flag=1;
						break;
					}
					fscanf(fp1, "%d%s%s%d%d%d%d%d%f%s%s",&rollno,name,day,&marks[0],
							&marks[1],&marks[2],&marks[3],&marks[4],&avg,branch,phone);
				}
				if(flag==0)
				{
					printf("\n\nRecord not found");
				}
				break;
		case 2: printf("Enter name");
				scanf("%s",n);
				fscanf(fp1, "%d%s%s%d%d%d%d%d%f%s%s",&rollno,name,day,&marks[0],
						&marks[1],&marks[2],&marks[3],&marks[4],&avg,branch,phone);
				while(!feof(fp1))
				{

					if(strcmp(n,name)==0)
					{
						printf("Record Found\n");
						printf("%d\t\t%s\t\t%s\t\t%d %d %d %d %d\t%f\t\t%s\t\t%s\n",rollno,
								name,day,marks[0],marks[1],marks[2],marks[3],marks[4],avg,
								branch,phone);
						flag=1;
						break;
					}
					fscanf(fp1, "%d%s%s%d%d%d%d%d%f%s%s",&rollno,name,day,&marks[0],
							&marks[1],&marks[2],&marks[3],&marks[4],&avg,branch,phone);
				}
				if(flag==0)
				{
					printf("\n\nRecord not found");
				}
				break;
		case 3: printf("Enter phone no");
				scanf("%s",p);
				fscanf(fp1, "%d%s%s%d%d%d%d%d%f%s%s",&rollno,name,day,&marks[0],
						&marks[1],&marks[2],&marks[3],&marks[4],&avg,branch,phone);
				while(!feof(fp1))
				{
					if(strcmp(p,phone)==0)
					{
						printf("Record Found");
						printf("%d\t\t%s\t\t%s\t\t%d %d %d %d %d\t%f\t\t%s\t\t%s\n",rollno,
								name,day,marks[0],marks[1],marks[2],marks[3],marks[4],avg,
								branch,phone);
						flag=1;

						break;
					}
					fscanf(fp1, "%d%s%s%d%d%d%d%d%f%s%s",&rollno,name,day,&marks[0],
							&marks[1],&marks[2],&marks[3],&marks[4],&avg,branch,phone);
				}
				if(flag==0)
				{
					printf("\n\nRecord not found");
				}
				break;
		default:printf("enter only 1 2 or 3");
		}
		fclose(fp1);
	}
	else
	{
		printf("\nError.File not found.\n");
		exit(0);
	}
}
void display(FILE *fp1,char arr[max])
{


	int rollno,marks[5];
	char name[max],phone[11],day[11],branch[5];
	float avg;
	fp1=fopen(arr,"r");
	if(fp1!=NULL)
	{

		fscanf(fp1, "%d%s%s%d%d%d%d%d%f%s%s",&rollno,name,day,&marks[0],
				&marks[1],&marks[2],&marks[3],&marks[4],&avg,branch,phone);
		while(!feof(fp1))
		{

			printf("%d\t\t%s\t\t%s\t\t%d %d %d %d %d\t%f\t\t%s\t\t%s\n",rollno,
					name,day,marks[0],marks[1],marks[2],marks[3],marks[4],avg,branch,phone);
			fscanf(fp1, "%d%s%s%d%d%d%d%d%f%s%s",&rollno,name,day,&marks[0],
					&marks[1],&marks[2],&marks[3],&marks[4],&avg,branch,phone);
		}
		fclose(fp1);
	}
	else
	{
		printf("\n\nError.File not found\n");
		exit(0);
	}
}
void modify(FILE *fp1,char arr[])
{
	int roll,rollno,marks[5]={0,0,0,0,0},flag=0,n=0,m=0;
		char name[max],phone[11],day[11],month[3],year[5],branch[5];
		char ch;
		float avg=0;
		fp1=fopen(arr,"r+");
		if(fp1!=NULL)
		{
			printf("enter roll no");
			scanf("%d",&roll);
			fscanf(fp1, "%d%s%s%d%d%d%d%d%f%s%s",&rollno,name,day,&marks[0],
					&marks[1],&marks[2],&marks[3],&marks[4],&avg,branch,phone);
			while(!feof(fp1))
			{

				if(roll==rollno)
				{

					printf("Record Found\n");
					flag=1;
					gname(name);
					gphone(phone);
					gdate(day,month,year);
					gmarks(marks,&avg);
					gbranch(branch);
					if(m==0)
					{
						fseek(fp1,m,SEEK_SET);
					}
					else
					{
						fseek(fp1,m+1,SEEK_SET);
					}

					fprintf(fp1,"%d\t\t%s\t\t%s-%s-%s\t\t%d %d %d %d %d\t%f\t\t%s\t\t%s\n",roll,
							name,day,month,year,marks[0],marks[1],marks[2],marks[3],marks[4],avg,
							branch,phone);
					printf("\n\nRecord Modified\n\n");
					rewind(fp1);
					printf("hello");
					fclose(fp1);
					break;

				}
				m=ftell(fp1);
				fscanf(fp1, "%d%s%s%d%d%d%d%d%f%s%s",&rollno,name,day,&marks[0],
						&marks[1],&marks[2],&marks[3],&marks[4],&avg,branch,phone);
			}
			if(flag==0)
			{
				printf("\n\nRecord not found");
				fclose(fp1);
			}

		}
		else
		{
			printf("File not found");
			exit(0);
		}

}
void del(FILE *fp1,char arr[])
{
	FILE *fp2;
	//printf("enter name of temporary file");
	//char arr2[max];
	//scanf("%s",arr2);
	char arr2[10];
	printf("Enter nameof temporary file");
	scanf("%s",arr2);
	fp2=fopen(arr2,"w");
	fp1=fopen(arr,"r");
	int choice,roll,rollno,marks[5]={0,0,0,0,0},flag=0;
	char name[max],phone[11],day[11],month[3],year[5],branch[5],n[max],p[11];
	char ch;
	float avg=0;
	printf("Enter roll no of student whose record you want to delete");
	scanf("%d",&roll);
	fscanf(fp1, "%d%s%s%d%d%d%d%d%f%s%s",&rollno,name,day,&marks[0],
			&marks[1],&marks[2],&marks[3],&marks[4],&avg,branch,phone);
	while(!feof(fp1))
	{
		if(roll==rollno)
		{
			printf("Record Found\n");
			flag=1;
		}
		else
		{

			fprintf(fp2,"%d\t\t%s\t\t%s\t\t%d %d %d %d %d\t%f\t\t%s\t\t%s\n",rollno,name,
					day,marks[0],marks[1],marks[2],marks[3],marks[4],avg,branch,phone);
		}
		fscanf(fp1, "%d%s%s%d%d%d%d%d%f%s%s",&rollno,name,day,&marks[0],
				&marks[1],&marks[2],&marks[3],&marks[4],&avg,branch,phone);
		}
		if(flag==0)
		{
			printf("\n\nRecord not found");
		}
		else if(flag==1)
		{
			fclose(fp1);
			int re=remove(arr);
			printf("%d\n",re);
			fclose(fp2);
			int ren=rename(arr2,arr);
			printf("%d\n",ren);
			if(ren==0)
			{
				printf("record deleted successfully\n");
			}
		}
}
int main()
{
	setbuf(stdout,NULL);
	FILE *fp1;
	char arr[max];
	int choice,a;
	while(1)
	{
		printf("\nMenu\nEnter\n1 to create  new file\n2 to open existing file\n3 to add data\n"
				"4 to display data\n5 to search data\n6 to modify data\n7 to delete data\n8 to exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1: create(fp1,arr);
				a=0;
				break;
		case 2: create(fp1,arr);
				a=1;
				break;
		case 3: add(fp1,arr,a);
				break;
		case 4: display(fp1,arr);
				break;
		case 5: searchdata(fp1,arr);
				break;
		case 6: modify(fp1,arr);
				break;
		case 7: del(fp1,arr);
				break;
		case 8:exit(0);
		}
	}
	return 0;
}

