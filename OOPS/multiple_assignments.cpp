#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

class personal
{
    protected:
        string name;
        char gender;
        string dob;
        
    public:
        void get_personal();
};

class professional
{
    protected:
        int xp_yrs;
        string company;
        int sal;
        
    public:
        void get_professional();
};

class acadmic           
{
    protected:
        int per;
        string college;
        string stream;
   
   public:
        void  get_acadmic();
}; 

class bio:public acadmic,public professional,public personal
{
    public:
        
        void display()
        {
            cout<<"----------Personal Data-----------\n\n";
            cout<<"Name : "<<name<<"\n";
            cout<<"Gender : "<<gender<<"\n";
            cout<<"dob : "<<dob<<"\n";
            
            
            cout<<"----------Professional Data-----------\n\n";
            cout<<"Years of experience : "<<xp_yrs<<"\n";
            cout<<"Firm Name: "<<company<<"\n";
            cout<<"Salary : "<<sal<<"\n";
            
            cout<<"----------Acadmic Data-----------\n\n";
            cout<<"Percentage : "<<per<<"\n";
            cout<<"College : "<<college<<"\n";
            cout<<"Stream of Education : "<<stream<<"\n";
        }
};


void acadmic::get_acadmic()
{
    cout<<"----------Acadmic Data-----------\n\n";
    cout<<"Enter Percentage : ";
    cin>>per;
    cout<<"\n\n";
    
    cout<<"Enter College Name : ";
    cin>>college;
    cout<<"\n\n";
    
    cout<<"Enter Stream of Education : ";
    cin>>stream;
    cout<<"\n\n"; 
}

void professional:: get_professional()
{
    cout<<"----------Professional Data-----------\n\n";
    cout<<"Enter Years of experience : ";
    cin>>xp_yrs;
    cout<<"\n\n";
    
    cout<<"Enter Company Name : ";
    cin>>company;
    cout<<"\n\n";
    
    cout<<"Enter Salary : ";
    cin>>sal;
    cout<<"\n\n"; 
}

void personal:: get_personal()
{
    cout<<"----------Personal Data-----------\n\n";
    cout<<"Enter Name : ";
    cin>>name;
    cout<<"\n\n";
    
    cout<<"Enter Gender : ";
    cin>>gender;
    cout<<"\n\n";
    
    cout<<"Enter date of birth : ";
    cin>>dob;
    cout<<"\n\n";
}

int main()
{
       bio b;
       b.get_personal();
       b.get_acadmic();
       b.get_professional();
       
       b.display();
}        
                         
