#include<stdio.h>
#include<stdlib.h>
struct node
{ 
 int data;
 struct node*next;
 };
void main()
 { 
   struct node*sp=(struct node*)0;
   struct node*push(struct node*,int);
   struct node* pop(struct node*,int*);
   int search(struct node*,int);
   int option,item,ans;
  
   do
   {
    printf("\n1.Push\n");
    printf("\n2.Pop\n");
    printf("\n3.Search\n");
    printf("\n4.Exit\n");
    printf("\n5.option\n");
    scanf("%d",&option);
    switch(option)
     {
      case 1:
             printf("Data:");
             scanf("%d",&item);
             sp=push(sp,item);
             break;
      case 2: 
             if(sp==(struct node*)0)
             printf("Stack empty");
             else
             {
             sp=pop(sp,&item);
             printf("popped item=%d\n",item);
             }
             break;
      case 3:
             printf("Data");
             scanf("%d",&item);
             ans=search(sp,item);
             if(ans!=0)
               printf("Found ");
             else
               printf("Not found\n");
             break;
      case 4:exit(0);
      }
    }
    while(1);
   }
   
   //function to push an item 
   struct node*push(struct node*sp,int data)
   {
     struct node*t;
     t=(struct node*)malloc(sizeof(struct node));
     t->data=data;
     t->next=sp;
     return t;
   }
   
   //function to pop an element
   struct node*pop(struct node*sp,int*item)
   {
     struct node*t=sp;
     if(sp!=(struct node*)0)
     { 
       *item=sp->data;
       sp=sp->next;
       free(t);
     }
     return sp;
     }
     
   //function to search an item
   int search(struct node*sp,int item)
    {
      while(sp!=(struct node*)0 && sp->data!=item)
      sp=sp->next;
      if(sp==(struct node*)0)
      return 0;
      else
      return 1;
      }
      
      
     
         
