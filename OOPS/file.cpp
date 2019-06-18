/* Roll no : 2002
   Name : TEJAS AGRAWAL
   Class : SE-10
   Batch : E-10
   ASSIGNMENT 10 : File Handling And Database
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#define MAX 15

using namespace std;

class student {

	private :
	
		char name[15];
		int roll_number;
		int clas;
		float per;
		int marks_1;
		int marks_2;
		int marks_3;
		
	
	public :
		
		student () 
		{
			roll_number = -1;
			clas = -1;
			marks_1 = -1;
			marks_2 = -1;
			marks_3 = -1;
			per = 0.0;
		}
		
		void getdata ();
		void displaydata ();
		
		int getroll (int r) 
		{
			if (r==roll_number) return 1;
			else  return 0;
		}
		
		int search (int r)
		 {
			fstream file;student s;
			file.open("student.txt", ios::in | ios::binary);
			file.read( (char *) &s, sizeof(s));
				
				 while (file)
				  { 
					if (s.getroll(r))
					{
						file.close();
						return 1;
					}
			        file.read( (char *) &s, sizeof(s));
				}
				
			file.close();
			return 0;
		}
};

void student::getdata()
 {

	cout<<"\nEnter Name : ";
	cin>>name;
	
	cout<<"\nEnter Roll No : ";
	cin>>roll_number;
	
	cout<<"\nEnter class : ";
	cin>>clas;
	
	cout<<"\nEnter Marks (out of 100) ";
	
	cout<<"\nEnter Marks for subject 1 : ";
	 cin>>marks_1;
	 
	cout<<"Enter Marks for subject 2 : "; 
	cin>>marks_2;
	
	cout<<"Enter Marks for subject 3 : "; 
	cin>>marks_3;
	
	per = marks_1 + marks_2 + marks_3;
	
	per = per/300;
	per = per * 100;

}


void student::displaydata()
 {
					cout << left ;
					cout << setw(15) << name;
					cout << setw(8) << roll_number;
					cout << setw(6) << clas;
					cout << setprecision(3) << setw(11) << per;
					cout << setw (8) << marks_1;
					cout << setw (6) << marks_2;
					cout << setw (10) << marks_3 << endl;
}


int main () 
{
	
	student s,s1;
	static int record_count;
	int choice,flag,r,i,n;
	fstream file,temp;

	file.open("student.txt", ios::out | ios::binary);
	file.close();

	do 
	{
		
		cout << "\n\nEnter 0 to Exit ";
		cout << "\n 1. to Add Record ";
		cout << "\n 2. to Display Data ";
		cout << "\n 3. to Delete Data ";
		cout << "\n 4. to Modify Data : ";
		cin >> choice ;
		
		switch (choice) 
		{
			
		case 0 : break;
		
		case 1 : cout << "\nEnter How Many Records : "; 
				 cin >> n;
				 file.open("student.txt", ios::out | ios::in | ios::binary | ios::ate);
				 for (i=0;i<n;i++) 
				 {
				 	cout << "\n :: RECORD " << record_count+1 << " ::\n";		
				 	s.getdata();
				 	cout << "**************************************************\n";
				 	file.write((char *) &s, sizeof(s));
				    record_count++;
				 }
				 
				 file.close();
				 break;
				 				 
		case 2 : if (record_count != 0) 
		        {
				 cout << "\n ************************** DATABASE *************************** \n";
				 cout << "\n                                        |        MARKS        |" ;
				 cout << "\nName\t       Roll_No Class Percentage Physics Maths Chemistry \n" << endl;
				 file.open("student.txt", ios::out | ios::in | ios::binary | ios::ate);
				 file.seekg(0);
				 
				 while ( file.read( (char *) &s, sizeof(s)) )
				 {
					s.displaydata();
				 }
				 
				 file.close();
				 cout << "\n\n *************************************************************** \n";
			  }
				 else cout << "\nPLEASE ADD RECORD... DATABASE EMPTY ";
				 break;
				 
		case 3 : if (record_count!=0) 
		        {

				 cout << "\n ************************* DELETE RECORD ************************* \n";
				 file.open("student.txt", ios::out | ios::in | ios::binary | ios::ate);
				 file.seekg(0);
				 temp.open("temp.txt", ios::out | ios::binary);
    			 cout << "\n Enter Roll No Of Record To Be Deleted : ";
				 cin >> r; i=0;
				 file.read( (char *) &s, sizeof(s));
				 while (file)
				 {
					if (s.getroll(r) == 0) 
					{
						temp.write( (char *) &s, sizeof(s));
						i++;
					}
			    file.read( (char *) &s, sizeof(s));
				}

				if (i==record_count)
			 {
					
				cout << "\n** RECORD NOT FOUND **";
				file.close();
				temp.close(); 
			}
				else 
				{
					cout << "\n ** RECORD DELETED **";
					record_count--;
					file.close();
				 	temp.close();
					remove ("student.txt");
					rename ("temp.txt", "student.txt");
				}
				 
				 cout << "\n\n *************************************************************** \n";}
				 else cout << "\nPLEASE ADD RECORD... DATABASE EMPTY ";
				 break;
				 
		case 4 : if (record_count != 0)
		 {
				 cout << "\n ************************* MODIFY RECORD ************************* \n";
			     file.open("student.txt", ios::out | ios::in | ios::binary | ios::ate);
				 file.seekg (0);
				 cout << "\n Enter Roll No Of Record To Be Modified : ";
				 cin >> r;
				 flag = 0; i=0;
					 
 				 file.read( (char *) &s, sizeof(s));
				 while (file)
				  { 
					
					if (s.getroll (r))
					{
						flag++;
						file.seekg( (i*sizeof(s)), ios::beg);
						s.getdata();
						file.write( (char *) &s, sizeof(s));
						break;
					}
				    i++;
				    file.read( (char *) &s, sizeof(s));
				}
				 
				 if (flag == 0) cout << "\n** RECORD NOT FOUND **" ;
				 file.close();
				 cout << "\n\n *************************************************************** \n"; }
				 else cout << "\nPLEASE ADD RECORD... DATABASE EMPTY ";
				 break;
			
		default : cout << "\nPlease Enter Valid Choice ";
				  break;
		
	}
}while (choice!=0);
	
	return 0;
}
