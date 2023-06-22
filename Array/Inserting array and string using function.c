/*
2. Inserting: Insert
a) 54 to a sorted array. b) Rahim to a sorted array. c) 99 to position 5. d) Karim to position 5.
*/
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define STR 10
#define LEN 50

char a[STR][LEN];
int n;
void sort(char a[][LEN], int n);
int value(char a[][LEN], int n);
int index(char a[][LEN], int n);


int main(){

    printf("Enter Size of array: ");
    scanf("%d",&n);

    printf("Enter Strings of the array: \n");

    for(int i=0;i<n;i++){
        scanf("%s",a[i]);
    }

    int choice;

    while(1){
        printf("\n\n:::Menu:::\n");
        printf("1. Sort\n");
        printf("2. Insert String with Value\n");
        printf("3. Insert String with Index\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1: sort(a,n);
                    break;
            case 2: n = value(a,n);
                    break;
            case 3: n = index(a,n);
                    break;
            case 4: exit(0);
            default: printf("Enter valid input...");
        }
    }

    return 0;
}


void sort(char a[][LEN], int n){

    char temp[100];

    for(int i=0;i<(n-1);i++){
        int j_min = i;
        for(int j=i+1;j<n;j++){
            if(strcmp(a[j],a[j_min])<0){
                j_min=j;
            }
        }
        if(j_min != i){
            strcpy(temp, a[i]);
            strcpy(a[i],a[j_min]);
            strcpy(a[j_min],temp);
        }
    }
    for(int i=0;i<n;i++){
        printf("%s\n",a[i]);
    }

}

int value(char a[][LEN], int n){

    char item[LEN];
    int position;
    printf("Enter String to be inserted: ");
    scanf("%s",item);

    for(int i=0;i<n;i++){

        if (strcmp(item,a[i])<0){
            position = i;
            break;
        }else{
            position = i+1;
        }
    }

    for(int j=n+1;j>=position;j--){
            strcpy(a[j], a[j-1]);
    }

    strcpy(a[position], item);

    n=n+1;

    printf("\n\nThe final array: ");
    for(int k=0;k<n;k++){
        printf(" %s ", a[k]);
    }

    return n;
}


int index(char a[][LEN], int n){

    int indexValue;
    char item[LEN];

    printf("\nEnter index no. to insert the data: ");
    scanf("%d",&indexValue);
    printf("Enter data to be inserted: ");
    scanf("%s",item);

    for(int j=n+1;j>=indexValue;j--){
            strcpy(a[j],a[j-1]);
    }

    strcpy(a[indexValue-1],item);
    n=n+1;

    printf("\n\nFinal Array elements: ");

    for(int i=0;i<n;i++){
        printf(" %s ",a[i]);
    }
    return n;
}
