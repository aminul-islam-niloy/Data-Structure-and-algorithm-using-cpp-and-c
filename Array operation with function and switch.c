
#include<stdio.h>
int main()
{
    int array[100],i,j,n,findNum,pos,value,temp,choice,loop;

    printf("\n Enter Array Size: ");
    scanf("%d",&n);
    printf("Enter Array Element: ");
    for(i=0; i<n; i++){
        scanf("%d",&array[i]);
    }
    loop = 1;
    while(loop != 0){
    puts("Array operation:");
      puts("1 - Search");
      puts("2 - Delete");
      puts("3 - Sort");
      puts("0 - Exit");
      printf("Your choice: ");
      scanf("%d",&choice);
      printf("You've Choose for ");

  switch(choice)
  {
    case 1:
      printf("1. search an array,\n ");

    printf("Enter a number to search: ");
    scanf("%d", &findNum);

    for(i=0; i<n; i++){
        if(array[i]==findNum)
            break;
    }
    if(i<n){
        printf("\nElement found at index: %d",i);
    }
    else{
        printf("Element not found.");
    }


      break;

    case 2:

    printf("\nEnter the element position to delete : ");
    scanf("%d", &pos);
    if(pos < 0 || pos > n)
    {
        printf("Invalid position! Please enter position between 1 to %d",n);
    }
    else
    {
        for(i=pos-1; i<n-1; i++)
        {
            array[i] = array[i + 1];
        }
        n--;
    printf("array after deleting the value is\n");
   for(i=0;i<n;i++)
   {
     printf("%d\n",array[i]);
   }
      break;

    case 3:
      printf("3. Sort the array\n ");

    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
           if(array[j]>array[j+1])
           {
           	temp=array[j];
           	array[j]=array[j+1];
           	array[j+1]=temp;
		   }
        }
    }
    printf("\n array elements in ascending order:\n ");

    for(i=0; i<n; i++)
    {
       printf("%d ",array[i]);
    }
       break;
    case 0:
        loop = 0;
       default:
      printf("Wrong choice & exit");
  }
  }
    }

  return(0);
}



