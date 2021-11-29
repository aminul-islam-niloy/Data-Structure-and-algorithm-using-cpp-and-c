#include<stdio.h>
int main()
{

   int array[100],i,x,n,search,first,last,mid;
   printf("How much number do you want to search:");
   scanf("%d",&n);

   printf(" Enter number of %d :\n",n);
   for(i=0;i<n;i++)
    {
      printf("%d number =",i);
      scanf("%d",&array[i]);
   }

   printf("Enter targeted number:");
   scanf("%d",&search);


   first=0;
   last=n-1;
   mid=(first+last)/2;

   while(first<=last)
   {

       if(array[mid]<search)
        first=mid+1;

        else if(array[mid]==search)
        {
            printf("%d found the element: %d\n",search,mid+1);
            break;
        }
        else
            {
            last=mid-1;
             mid=(first+last)/2;
        }

   }
   if(first>last)
    printf("Element not found",search);
   return 0;
}
