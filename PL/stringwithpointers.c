
/*

ASSIGNMENT          :  3
NAME                : TEJAS SANJIV AGRAWAL
ROLL NUMBER         : 2002
BATCH               : E-10
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 60


void getstring (char *p); //gets string from user
void printstring (char *p); //for printing string
int stringlength (char *p); //gives length of string
int stringpalindrome (char *p); //for checking palindrome
int stringcompare (char*p); //for comparing to strings for equality (case sensitive)
void copystring (char *p2, char *p1); //for copying string
void stringreverse (char *p1); //for reversing string
int substring (char *p, int *loc); //for finding substring*/

int main () {
	
	char string[MAX]="\0",reverse[MAX],copy[MAX];
	int choice,i,flag,loc[20];
	
	getstring (string);
	system ("clear");
	
	do {
		printf ("\n\nEnter 0 to exit ");
		printf ("\nEnter 1 to update String ");
		printf ("\nEnter 2 to Print String ");
		printf ("\nEnter 3 to find length of string ");
		printf ("\nEnter 4 to Check Weather String Is Palindrome Or Not ");
		printf ("\nEnter 5 to Compare Strings ");
		printf ("\nEnter 6 to copy string ");
		printf ("\nEnter 7 to reverse string ");
		printf ("\nEnter 8 to to check for subsring ");
		printf ("\nEnter 9 to clear screen ");
		printf ("\nEnter your choice : ");
		scanf ("%d",&choice);
		
		switch (choice) {

			case 0 :break;				
	
			case 9 :system ("clear");
					break;
					
			case 1 :getstring (string);
				    break;

			case 2 :printf ("\nSTRING = %s", string);					
				 	break;

			case 3 :flag = stringlength(string);
					printf ("\nLength Of String = %d",flag);
					break;

			case 4 :flag = stringpalindrome (string);
					if (flag==1) printf ("\nString is palindrome ");
					else printf ("\nString is not palindrome ");
					break;
					 
			case 5 :flag = stringcompare (string);
					if (flag==1) printf ("\nStrings are equal ");
					else printf ("\nStrings are not equal ");
					break;	 

			case 6 :copystring (copy, string);
				 	printf ("\nOriginal String = %s, Copied String = %s",copy,string);
					break;

			case 7 :copystring (copy, string);
					stringreverse (copy);
					printf ("\nREVERSE STRING = %s",copy);
					break;
					 
			case 8 :flag = substring (string,loc);
					if (flag!=0) {
					printf ("\nThe String is subset of given string and occured %d time ",flag);
					for (i=0;i<flag;i++) printf ("\nat location %d", loc[i]); }
	 				else printf ("\nString Is not a substring ");
					break; 

			default :printf ("\nPlease Enter A Valid Option : ");
					 break;
				}
}while(choice!=0); //end of menu program
return 0;
} // end of main

void getstring (char *p) {
	printf ("\nEnter String (max length 60 characters): ");
	scanf ("%s",p);
} //end of get string function

void printstring (char *p) {
	printf ("%s",p);
} //end of printstring function

int stringlength (char *p) {
	int i;
	for (i=0;*p!='\0';i++,p++);
	return i;
} //end of stringlength function

int stringpalindrome (char *p) {
	int l,i,j,flag=0;
	l = stringlength (p);
	for (i=0,j=l-1;i<l/2;i++,j--) {
		if (p[i] != p[j]) {
			flag ++;
			break;
		}
	}
	if (flag == 0) return 1;
	else return 0;
} //end of stringpalindrome function

int stringcompare (char *p) {
	char string1[MAX];
	int i,j,flag=0;
	printf ("\nEnter The String To be Compared With : ");
	getstring (string1);
	for (i=0;i<stringlength(p);i++) {
		
		if (p[i]!=string1[i]) {
			flag++;
			break;
		}
	}
	
	if (flag==0) return 1;
	else return 0;
} //end of stringcompare function

void copystring (char *p2, char *p1) {
	int i;
	for (i=0;i<=stringlength (p1);i++) p2[i] = p1[i];
} //end of copystring function

void stringreverse (char *p1) {
	char temp;
	int i,j,l;
	for (i=0,j=stringlength (p1)-1;i<stringlength (p1)/2;i++,j--) {
		temp = p1 [j];
		p1 [j] = p1 [i];
		p1 [i] = temp;
	}
} //end of stringreverse program

int substring (char *p1, int *loc) {
	char substring[MAX];
	int i,j,k,p,count=0,length,flag;
	printf ("\nEnter Substring : ");
	scanf ("%s",substring);
	length = stringlength (substring);
	for (i=0;i<stringlength(p1);i++) {
	 		p=0;flag=0;
	 		if (p1[i] == substring[p]) {
	 				for (k=0,j=(i+1);k<(length-1);k++,j++) {
	 				p++;
	 				if (p1[j]!=substring[p]) {
	 					flag++;
	 					break;
					 }
				 }
				 if (flag==0) flag = -1;
				}
		if (flag==-1) {loc[count] = i+1; count++;}
	 }
	 
	 if (count != 0) {
	 		return count;
	 }
	 else {
	 		return 0;
	 }
}//end of substringfunction 
