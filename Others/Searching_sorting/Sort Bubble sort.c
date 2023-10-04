#include<stdio.h>
int main()
{

   int array[100],i,j,temp;
   int n=sizeof(array)/sizeof(array[0]);

   printf("How much number do you want to search:");
   scanf("%d",&n);

   printf(" Enter %d element :\n",n);
   for(i=0;i<n;i++)
    {
      printf("%d number =",i);
      scanf("%d",&array[i]);

   }
    printf("Print unsorted list: \n");

    for(i=0;i<n;i++)
    {
        printf(" %d ",array[i]);
    }

   for(i=0;i<n-1;i++)
   {
       for(j=0;j<n-i-1;j++)
       {
           if(array[j]>array[j+1])
           {
               temp=array[j];
               array[j]=array[j+1];
               array[j+1]=temp;
           }
       }
   }
printf("\n Print sorted list :\n");

    for(i=0;i<n;i++)
    {
        printf(" %d ",array[i]);
    }
    return 0;
}
