/* Roll no : 2007
   Name : Sagar Barapatre
   Class : SE-10
   Batch : E-10
   EXTRA ASSIGNMENT 3
*/
#include <iostream>
#include <string.h>
#define MAX 50
using namespace std;

template <class T>
void bubble_sort (T S[], int n) 
{
	
	T temp;
	int flag;
	
	for (int i=0 ; i<n-1 ; i++) 
	{
		flag = 0;
		for (int j=0 ; j<n-1-i ; j++) 
		{
			
			if (S[j] > S[j+1])
			 {
				
				temp = S[j];
				S[j] = S[j+1];
				S[j+1] = temp;
				flag++;
			}
		}
		
		if (flag == 0) break;
	}
	
}

template <class T>
void print (T S[], int n)
 {
	
	for (int i=0 ; i<n ; i++) cout << S[i] << " ";
	cout << endl;
}
 

int main () 
{
	
	int i,n,S[20];
	float b[20];
	char c[20];
		
	
	cout << "\nEnter Length of Integer Array : ";
	cin >> n;
	
	cout << "Enter Elements : ";
	
	for (i=0;i<n;i++)
	 {
		
		cin >> S[i];
	}
	
	cout << "\n Integer List : ";
	print (S, n);
	bubble_sort (S, n);
	
	cout << "\n Sorted Integer List : ";
	print (S, n);
	
	cout << "\n-----------------------------------------------\n";
	
	
	cout << "\nEnter Length of Float list : ";
	cin >> n;
	
	cout << "Enter Elements : ";
	for (i=0;i<n;i++) 
	{
		cin >> b[i];
	}
	
	cout << "\n Float List : ";
	print (b, n);
	bubble_sort (b, n);
	cout << "\n Sorted Float List : ";
	print (b, n);	
	
	cout << "\n-----------------------------------------------\n";
	
	cout << "\nEnter Length of char array : ";
	cin >> n;
	
	cout << "Enter Elements : ";
	for (i=0;i<n;i++)
	 {
		cin >> c[i];
	}
	
	cout << "\n Character List : ";
	print (c, n);
	bubble_sort (c, n);
	cout << "\n Sorted Character List : ";
	print (c, n);
	return 0;
}
