#include<iostream>
#include<stdlib.h>
//#include<char>
#include<cstdio>
using namespace std;

class A
{
    protected:
        char name[20],dob[10],bg[5];
    
    public:
    
        void accept()
        {
            cout<<"Enter Your Name : ";
            cin>>name;
            cout<<"\n";
            
            cout<<"Enter your Date Of Birth : ";
            cin>>dob;
            cout<<"\n";
            
            cout<<"Enter your blood group : ";
            cin>>bg;
            cout<<"\n\n";
        }
        
        void display()
        {
            cout<<"-------------------------------------------------------------------\n\n";
            printf("%20s %10s \t%5s\n","Name","DOB","Blood Group");
            cout<<"-------------------------------------------------------------------\n\n";
            printf("%20s\t %10s %5s\n\n",name,dob,bg);
        }
        
};

class B
{
    protected:
        float wt,ht;
    
    public:
    
        void accept1()
        {
            cout<<"Enter Your Height : ";
            cin>>ht;
            cout<<"\n";
            
            cout<<"Enter Your Weight: ";
            cin>>wt;
            cout<<"\n\n";
        }

        void display1()
        {
            cout<<"-------------------------------------------------------------------\n\n";
            printf("%10s %10s\n","Height","Weight");
            cout<<"-------------------------------------------------------------------\n\n";
            printf("%5f \t%5f\n\n",ht,wt);
        }        
        
    
};

class C
{
    protected:
        char pol_no[10],ph_no[10],add[20];
    
    public:
    
        void accept2()
        {
            cout<<"Enter Your Policy Number : ";
            cin>>pol_no;
            cout<<"\n";
            
            cout<<"Enter Your Phone number : ";
            cin>>ph_no;
            cout<<"\n";                        
        
            cout<<"Enter Your Address (Line seperated by ',') : ";
            cin>>add;
            cout<<"\n\n"; 
        }
        void display2()
        {
            cout<<"-------------------------------------------------------------------\n\n";
            printf("%10s %12s %20s\n","Policy Number","Phone","Address");
            cout<<"-------------------------------------------------------------------\n\n";
            printf("%10s %12s %20s\n\n",pol_no,ph_no,add);
        }  
    
};

class D: public A,public B,public C
{
    
    public:
        
        char tel_no[10];
        int lic_no;
        void accept3()
        {
            cout<<"Enter Your Telephone Number : ";
            cin>>tel_no;
            cout<<"\n";
            
            cout<<"Enter Your Driving License number : ";
            cin>>lic_no;
            cout<<"\n\n";                        
        } 
        
        void display3()
        {
            cout<<"-------------------------------------------------------------------\n\n";
            printf("%12s \t%10s\n","Telephone","License");
            cout<<"-------------------------------------------------------------------\n\n";
            printf("%12s %10d\n\n",tel_no,lic_no);
        } 
        
        void display_all()
        {
            printf("%20s\t %10s %5s %5f \t%5f %10s %12s %20s %12s %10d\n\n",name,dob,bg,ht,wt,pol_no,ph_no,add,tel_no,lic_no);
        }
    
};

int main()
{
    D d[10];
    
    int ch,n,m;       //n=no of records
    
    do
    {
        cout<<"---------------------Menu-------------------\n\n";
        cout<<"\t1.Master class \n\t2.Insert \n\t3.Search \n\t4.Edit \n\t5.Display \n\t6.Delete \n\t7.Exit\n\n";
        cout<<"Your Choice is : ";
        cin>>ch;
        cout<<endl;
        
        switch(ch)
        {
            case 1:
            {
                cout<<"Enter number of records you want to enter : ";
                cin>>n;
                cout<<endl;
                
                for(int i=0;i<n;i++)
                {
                    d[i].accept();
                    d[i].accept1();
                    d[i].accept2();
                    d[i].accept3();
                }                
                
                break;
            }
            
            case 2:
            {
                cout<<"Enter number of records you want to insert : ";
                cin>>m;
                cout<<endl;
                
                for(int i=n;i<m;i++)
                {
                    d[i].accept();
                    d[i].accept1();
                    d[i].accept2();
                    d[i].accept3();
                }   
                
                n=n+m;
                               
                break;
            }
            
            case 3:
            {
                int i,l;
                cout<<"Enter Liscense no. you want to search : ";
                cin>>l;
                cout<<endl;
                
                for(i=0;i<n;i++)
                {
                    if(d[i].lic_no == l)
                    {
                        cout<<"Found\n\n";
                        
            cout<<"-------------------------------------------------------------------\n\n";
            printf("%20s %10s \t%5s %10s %10s %10s %12s %20s %12s \t%10s\n","Name","DOB","Blood Group","Height","Weight","Policy Number","Phone","Address","Telephone","License");
            cout<<"-------------------------------------------------------------------\n\n";
                        d[i].display_all();
                        break;
                    }
                }
                
                if(i==n)
                    cout<<"No such record exists\n\n";
                                
                break;
            }
            
            case 4:
            {
                int i,l;
                cout<<"Enter Liscense no. you want to search : ";
                cin>>l;
                cout<<endl;
                
                for(int i=0;i<n;i++)
                {
                    if(d[i].lic_no == l)
                    {
                        cout<<"Found\n\n";
                        d[i].accept();
                        d[i].accept1();
                        d[i].accept2();
                        d[i].accept3();
                        
                        break;
                    }
                }
                
                break;
            }
            
            case 5:
            {
            cout<<"-----------------------------------------------------------------------------------------------------\n\n";
            printf("%20s %10s \t%5s %10s %10s %10s %12s %20s %12s \t%10s\n","Name","DOB","Blood Group","Height","Weight","Policy Number","Phone","Address","Telephone","License");
            cout<<"-----------------------------------------------------------------------------------------------------\n\n";
                for(int i=0;i<n;i++)
                {
                    d[i].display_all();
                }
                break;
            }
            
            case 6:
            {
                int i,l;
                cout<<"Enter Liscense no. you want to search : ";
                cin>>l;
                cout<<endl;
                
                for(int i=0;i<n;i++)
                {
                    if(d[i].lic_no == l)
                    {
                        cout<<"Deleted\n\n";                        
                        
                        for(int j=i;j<n-1;j++)
                        {
                            d[j]=d[j-1]; 
                        }
                        
                        n--;
                        break;
                    }
                }
                    
                
                break;
            }
            
            case 7:
            {
                exit(0);
            }
        
        }
    }
    while(1);
     
           
   return 0;
}
                     
             
