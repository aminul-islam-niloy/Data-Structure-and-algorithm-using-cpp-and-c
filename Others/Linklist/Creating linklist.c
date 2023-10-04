#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node*next;
};

int main()
{
  struct node *a=NULL;
  struct node *b=NULL;
  struct node *c=NULL;
  struct node *d=NULL;
  struct node *e=NULL;
  struct node *f=NULL;

  a=(struct node*)malloc(sizeof(struct node));
  b=(struct node*)malloc(sizeof(struct node));
  c=(struct node*)malloc(sizeof(struct node));
  d=(struct node*)malloc(sizeof(struct node));
  e=(struct node*)malloc(sizeof(struct node));
  f=(struct node*)malloc(sizeof(struct node));


  a->data =5;
  b->data =3;
  c->data =9;
  d->data =42;
  e->data =0;
  f->data =10;

  a->next =b;
  b->next =c;
  c->next =d;
  d->next =e;
  e->next =f;
  f->next =NULL;

  printf("\n Print the value of link list :\n");
  while(a!=NULL)
    {
    printf("%d ->",a->data);
  a=a->next;
  }
return 0;
}
