
/* Assignment 8 : TEMPLATES
   Roll No.     :  2002
   Name         :  Tejas Agrawal
   Batch        :  E-10
   Dept         : IT
   
*/

#include<iostream>
using namespace std;
template <class T>

class matrix
{
    int row,col;
    T mat[20][20];
   
   public:
    void getdata();
    void display();
    void addition(matrix,matrix);
    void subtraction(matrix,matrix);
    void multiplication(matrix,matrix);
};

template <class T>
void matrix<T>::getdata()
{
  int i,j;
  
    cout<<"\n"<<"Enter no. of rows an columns:";
    cin>>row>>col;
    
    cout<<"\n"<<"Enter the elements:"<<"\n";
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            cin>>mat[i][j];
}

template <class T>       
void matrix<T>::display()
{
  int i,j;
  
    cout<<"\n";
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
}


template <class T>
void matrix<T>::addition(matrix mat1,matrix mat2)
{
  int i,j;

    cout<<"\n"<<"Addition:"<<"\n";
    if(mat1.row==mat2.row && mat1.col==mat2.col)
    {
        row=mat1.row;
        col=mat1.col;
        for(i=0;i<mat1.row;i++)
        {
            for(j=0;j<mat1.col;j++)
            {
                mat[i][j]=mat1.mat[i][j]+mat2.mat[i][j];
            }
        }
    }
    else
        cout<<"\n"<<"Addition is not possible"<<"\n";    
}


template <class T>
void matrix<T>::subtraction(matrix mat1,matrix mat2)
{
  int i,j;

    cout<<"\n"<<"Subtraction:"<<"\n";
    if(mat1.row==mat2.row && mat1.col==mat2.col)
    {
        row=mat1.row;
        col=mat1.col;
        for(i=0;i<mat1.row;i++)
        {
            for(j=0;j<mat1.col;j++)
            {
                mat[i][j]=mat1.mat[i][j]-mat2.mat[i][j];
            }
        }
    }
    else
        cout<<"\n"<<"Subtraction is not possible"<<"\n";
    
}


template <class T>
void matrix<T>::multiplication(matrix mat1,matrix mat2)
{
  int i,j,k;
  
    cout<<"\n"<<"Multiplication:"<<"\n";
    if(mat1.col==mat2.row)
    {
        row=mat1.row;
        col=mat2.col;
        for(i=0;i<mat1.row;i++)
        {
            for(j=0;j<mat2.col;j++)
            {
                mat[i][j]=0;
                for(k=0;k<mat1.col;k++)
                    mat[i][j]=(mat[i][j] + (mat1.mat[i][k]*mat2.mat[k][j]));
            }
        }
    }
    else
        cout<<"\n"<<"Multiplication is not possible"<<"\n";
}


int main()
{
  int ch;
  matrix<int> mat1,mat2,res;
  matrix<float> mat3,mat4,res1;
  
  do
  {
  cout<<"\n\t"<<"Do you want to do operation in:"<<"\n\t"<<"1.Integer"<<"\n\t"<<"2.Float"<<"\n\t"<<"3.Exit"<<"\n";
  cin>>ch;
  
    switch(ch)
    {
        case 1:
            mat1.getdata();
            mat1.display();
  
            mat2.getdata();
            mat2.display();
  
            res.addition(mat1,mat2);
            res.display();
  
            res.subtraction(mat1,mat2);
            res.display();
  
            res.multiplication(mat1,mat2);
            res.display();
            break;
            
        case 2:
            mat3.getdata();
            mat3.display();
  
            mat4.getdata();
            mat4.display();
          
            res1.addition(mat3,mat4);
            res1.display();
          
            res1.subtraction(mat3,mat4);
            res1.display();
          
            res1.multiplication(mat3,mat4);
            res1.display();
            break;
            
         case 3:
            break;
 
        default:
            cout<<"\n"<<"Invalid choice";
    }
  }while(ch!=3);
  
return 0;
}
