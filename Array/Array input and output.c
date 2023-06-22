#include<stdio.h>
int main ()
{

    int array[50],n=5,i;
    //printf("Enter array size:");
    //scanf("%d",&n);

    printf("Enter integer number of array:\n");
    for(i=0;i<n;i++)

      scanf("%d",array[i]);

    for(i=0;i<n;i++)
        {
           printf("%d\n",array[i]);
    }
return 0;
}
