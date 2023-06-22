#include<stdio.h>
int main()
{

   int array[100],i,x,n,search;
   printf("Enter array size:");
   scanf("%d",&n);

   printf(" Enter %d array number :\n",n);
   for(i=0;i<n;i++)
    {
      printf("%d number array=",i);
      scanf("%d",&array[i]);
   }

   printf("Enter targeted number:");
   scanf("%d",&search);


   for(i=0;i<search;i++)
   {
       if(array[i]==search)
        break;

   }
   if(i<n)
    printf("Element found in %d",i+1);
   else
    printf("Element not found");
}
