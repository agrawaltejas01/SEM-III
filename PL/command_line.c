/*

ASSIGNMENT          :  5
NAME                : TEJAS SANJIV AGRAWAL
ROLL NUMBER         : 2002
BATCH               : E-10
*/

#include<stdio.h>

int main(int argc,char *argv[])
{
    if(argc<3)
        printf("Insufficient arguments\n");
    
    FILE *c,*p;
    
    c=fopen(argv[1],"r");
    p=fopen(argv[2],"w");
    
    char x;

    do
    {
        x=fgetc(c);
        
        if(x==EOF)
            break;
        
        else
        {
            fputc(x,p);
        }
    }
    while(1);
    
    fclose(p);
    
    printf("File copid\n");
    
    printf("\t\t Contents are \n\n");
    
    p=fopen(argv[2],"r");
    
    do
    {
        x=fgetc(p);
          
       // printf("%c",x);
        if(x==EOF)
            break;
        
        else
            printf("%c",x);
    }
    while(1);
    
    printf("\n");
    
    fclose(c);
    fclose(p);
    
    return 0;
}
    
    
