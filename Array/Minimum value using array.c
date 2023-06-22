#include<stdio.h>
int main()
{
    int array[]={3, 6 ,9,14,7,4},i,n=6;
    int min=array[0];
    for(i=0;i<n;i++)
    {
        if(min>array[i])
        {
             min=array[i];

        }
    }
     printf("\n minimum value is %d\n",min);
return 0;
}

