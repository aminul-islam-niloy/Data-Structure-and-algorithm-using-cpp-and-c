#include<stdio.h>
int main()
{

    int array[]={4,6,7,8,9,7},i;
    float n=6;
    int total=0;
    float avg;
    for(i=0;i<n;i++)
    {
        total=total+array[i];
    }
    printf("sum of the total value=%d\n",total);

    avg=total/n;
    printf(" avarage of the total value=%f",avg);

    return 0;
}
