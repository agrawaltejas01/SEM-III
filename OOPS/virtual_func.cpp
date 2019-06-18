#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

class shape
{
     public:
     double x,y;
     virtual void getdata()=0;
     virtual void area()=0;
};

class rectangle:public shape
{
    public:
         double are;
         int base,height;
         void getdata()
         {
              cout<<"\nEnter Length : ";
              cin>>base;
              cout<<endl;
              
              cout<<"\nEnter Height : ";
              cin>>height;
              cout<<endl;
         }
         
         void area()
         {
            are=(base*height);
        }
        
         void display()
         {
            cout<<"area of rectangle is : "<<  are<<endl;
         }

};

class triangle:public shape
{
    public:
         double are;
         int base,height;
         void getdata()
         {
            cout<<"\nEnter Base of rectangle :  ";
            cin>>base;
            cout<<endl;
            
            cout<<"Enter Height of Rectangle : ";
            cin>>height;
            cout<<endl;
         }
         
         void area()
         {
            are=(0.5*height*base);
         }
         
         void display()         
          {
             cout<<"area of triangle is :"<<  are<<endl;
         }
};
int main()
{
    shape *s;
     triangle t;
     rectangle r;
    
    do 
    {
         cout<<"-------Menu---------\n\n";
         cout<<"\t1.Rectangle\n\t2.Triangle\n\t3.Exit\n";
         
         int ch;
         cout<<"Enter Choice : ";
         cin>>ch;
         cout<<endl;
         
         switch(ch)
         {
            case 1:
             {
                 cout<<"\n\n--------RECTANGLE ........\n\n";
                 s=&r;
                 s->getdata();
                 s->area();
                 r.display();
                 break;
            }
            
            case 2:
            {
                 cout<<"\n\n-----------TRIANGLE .........\n\n";
                 s=&t;
                 s->getdata();
                 s->area();
                 t.display();
                 break;
             }
            
            case 3:
                exit(0);
         }
     }
     while(1);
     
     return 0;
 }

