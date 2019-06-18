
/*

ASSIGNMENT          :  3
NAME                : TEJAS SANJIV AGRAWAL
ROLL NUMBER         : 2002
BATCH               : E-10
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 60


void getstring (char []); //gets string from user
void printstring (char []); //for printing string
int stringlength (char []); //gives length of string
int stringpalindrome (char []); //for checking palindrome
int stringcompare (char[]); //for comparing to strings for equality (case sensitive)
void copystring (char [], char []); //for copying string
void stringreverse (char []); //for reversing string
void substring (char[]); //for finding substring

int main () {
	
	char string[MAX]="\0",reverse[MAX],copy[MAX];
	int length,choice,i,flag;
	
	getstring (string);
	system ("clear");

	do {
		printf ("\n\nEnter 0 to exit ");
		printf ("\nEnter 1 to Enter A String ");
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

			case 0 : break;				
	
			case 9 :system ("clear");
			 	    break;

			case 1 :getstring (string);
				    break;

			case 2 :printf ("\nSTRING = %s", string);					
			      	break;

			case 3 :length = stringlength(string);
			    	printf ("\nLength Of String = %d",length);
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
					break;
					 
			case 8 :substring (string);
					break;

			default :printf ("\nPlease Enter A Valid Option : ");
					 break;
  	}
}while(choice!=0); //end of menu 
return 0;
} // end of main

void getstring (char string[]) {
	printf ("\nEnter String (max length 60 characters) : ");
	scanf ("%s",string);
} //end of get string function

void printstring (char print[]) {
	printf ("%s",print);
} //end of printstring function

int stringlength (char len[]) {
	int i;
	for (i=0;len[i]!='\0';i++);
	return i;
} //end of stringlength function

int stringpalindrome (char pal[]) {
	int l,i,j,flag=0;
	l = stringlength (pal);
	for (i=0,j=l-1;i<l/2;i++,j--) {
		if (pal[i] != pal[j]) {
			flag ++;
			break;
		}
	}
	if (flag == 0) return 1;
	else return 0;
} //end of stringpalindrome function

int stringcompare (char string[]) {
	char string1[MAX];
	int i,j,flag=0;
	printf ("\nEnter The String To be Compared With : ");
	scanf ("%s",string1);
	for (i=0;i<stringlength(string);i++) {
		if (string[i]!=string1[i]) {
			flag++;
			break;
		}
	}
	
	if (flag==0) return 1;
	else return 0;
} //end of stringcompare function

void copystring (char copy[], char string[]) {
	int l,i;
	l = stringlength (string);
	for (i=0;i<=l;i++) copy[i] = string[i];
} //end of copystring function

void stringreverse (char string[]) {
	char temp;
	int l,i,j;
	l = stringlength(string);
	for (i=0,j=l-1; i<l/2 ; i++,j--) {
		temp = string [j];
		string [j] = string [i];
		string [i] = temp;
	}
	printf ("\n REVERSE STRING = %s",string);
} //end of stringreverse program

void substring (char string[]) {
	 char substring[MAX];
	 int i,j,k,p,count=0,length,flag;
	 printf ("\nEnter Substring : ");
	 scanf ("%s",substring);
	 length = stringlength (substring);
	 for (i=0;i<stringlength(string);i++) {
	 		p=0;flag=0;
	 		if (string[i] == substring[p]) {
	 				for (k=0,j=(i+1);k<(length-1);k++,j++) {
	 				p++;
	 				if (string[j]!=substring[p]) {
	 					flag++;
	 					break;
					 }
				 }
				 if (flag==0) flag = -1;
				}
		if (flag==-1) count++;
	 }
	 if (count!=0) printf ("\nThe String is subset of given string and occured %d time ",count);
	 else printf ("\nString Is not a substring ");
}//end of substringfunction
