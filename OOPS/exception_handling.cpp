
/* Assignment 7 : EXCEPTION HANDELING
   Roll No.     :  2002
   Name         :  Tejas Agrawal
   Batch        :  E-10
   Dept         : IT
   
*/

#include<iostream>
using namespace std;

void getdata(double &x,double &y)
{
   cout<<"\nEnter the DIVIDEND and the DIVISOR\n";
   cin>>x>>y;
}

double divide(double x,double y)
{
    if(y==0)
    {
        throw 0;
    }
    return x/y;
}

int main()
{
    int ch;
    double x,y,ans;
    do{
    cout<<"\n1.Perform Division\n2.Exit\n";
    cin>>ch;
    switch(ch)
    {
     case 1: getdata(x,y);
             try
             {
               ans=divide(x,y);
               cout<<"The quotient is : "<<ans<<endl;  
             }
             catch(int m)
             {
               if(m==0)
               {
                  cout<<"Dividing by zero"<<endl;
               }
             }
             
      case 2: break;
      default: cout<<"\nInvalid choice\n";       
    
    }}while(ch!=2);
    return 0;
}

