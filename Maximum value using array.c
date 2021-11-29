#include<stdio.h>
int main()
{
    int array[]={4,5,6,7,8},i,n=5;
     int max=array[0];

    for(i=0;i<n;i++)
        {
        if(max<array[i])
            {
            max=array[i];
        }
    }
    printf("\n Maximum value: %d\n",max);
    return 0;

}
