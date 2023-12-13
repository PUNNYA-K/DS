#include<stdio.h> 
#include<stdlib.h>
struct node
  {
   int data;
   struct node*left,*right;
   };
void main()
    {
    struct node*insert(struct node*,int);
    struct node*delete(struct node*,int);
    struct node*search(struct node*,int);
    int option,data,item,ans;
    struct node*dl=(struct node*)0,*t;//dl=first node point 
    do
    { 
     printf("\n1.Insert\n");
     printf("\n2.Delete\n");
     printf("\n3.Search\n");
     printf("\n4.Exit\n");
     printf("\nOption");
     scanf("%d",&option);
      switch(option)
      { 
       case 1:printf("Data:");
      	      scanf("%d",&data);
      	      dl=insert(dl,data);
      	      break;
       case 2:printf("Item:");
      	      scanf("%d",&data);
      	      dl=delete(dl,data);
      	      break;
       case 3:printf("Item to search:");
      	      scanf("%d",&data);
      	      t=search(dl,data);
      	        if (t==(struct node*)0)
      	        printf("Not found");
      	        else
      	        printf("Found");
      	      break;
       case 4:exit(0);
       	      
      	}
      	}
      	while(1);    
       }
      	      
 //function to insert an item in doubly linked list
 
 struct node*insert(struct node*dl,int item)
 {
   struct node*t;
   t=(struct node*)malloc(sizeof(struct node));
   t->data=item;
   t->left=(struct node*)0;
   t->right=dl;
   if (dl!=(struct node*)0)
   
     dl->left=t;
     return t;//value goes to dl
  }
   
 //function to search an item in a doubly linked list
   
 struct node*search(struct node*dl,int item)
 {
   while(dl!=(struct node*)0 && dl->data!=item)
   dl=dl->right;
   return dl;
  }
  
 //function to delete an item in a doubly linked list
 
 struct node*delete(struct node*dl,int item)
  {
  struct node*t;
  t=search(dl,item);
  if(t==(struct node*)0)
  printf("not found\n");
  else
  {
   if(t->left==0 && t->right==0)
   dl=(struct node*)0;
   else if(t->left==(struct node*)0)//first node
   {t->right->left=t->left;
   dl=dl->right;
   }
    else if(t->right==(struct node*)0)//last node
    t->left->right=t->right;
    else
      {
      t->left->right=t->right;//interior node deletion
      t->right->left=t->left;
      }
    free(t);
    printf("%d deleted",item);
    }
    return dl;
    }
   
   
   
   
  
   
      
 
      	      
     
