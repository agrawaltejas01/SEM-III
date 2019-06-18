/* Roll no : 2007
   Name : Sagar Barapatre
   Class : SE-10
   Batch : E-10
   EXTRA ASSIGNMENT 4
*/

#include <iostream>
#include <string.h>
#define MAX 50
using namespace std;

class monitor {
	
	private :
			float val;
			float width;
			int model;
			int error;
	
	public :
			monitor () {val=0.0; width=0.0; model=0;}
			void getdata ();
			void putdata ();
			void error_msg ();
};

void monitor::getdata() 
{
	
	cout << "\nEnter Model Number : ";
	cin >> model;
	
	cout << "Enter price : ";
	cin >> val;
	
	cout << "Enter Screen Size In Inches : ";
	cin >> width;
	
	if ( (model > 9999) || (width<12 || width>150) || (val<0 || val>50000) )
		throw (error);
	
}

void monitor::putdata() 
{
	
	cout << "\nModel No : " << model;
	cout << "\nScreen Size : " << width << "\"";
	cout << "\nPrice : " << val ;
	
}

void monitor::error_msg() 
{
	
	cout << "\nERROR : EXCEPTION CAUGHT ";
	cout << "\nModel No : " << 0;
	cout << "\nScreen Size : " << 0.0;
	cout << "\nPrice : " << 0.0;
}


int main () 
{
	
	monitor m;
	
	try
	 {
		m.getdata ();
		m.putdata ();
	}
	catch (int)
	 {
		m.error_msg();
	}
	
	return 0;
}
