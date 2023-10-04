#inclue<stdio.h>
#include<math.h>

int main()
{

    int array[]={4,6,8,9},i,n=4;
    float sinvalue[n];
    for(i=0;i<n;i++)
        {
        sinvalue[i]=sin(array[i]);
    }
    printf("sin value of each element:",n);
    for(i=0;i<n;i++)
    {

        printf("sin value of %d is %f"array[i],sinvalue[i])
    }
    return 0;

}
