#include<stdio.h>
#include<stdlib.h>
#define size 10
int que[size];
int front=0,rear=0;
void main()
{
   void enque(int);
   int deque();
   int search(int);
   int option,item,ans;
   do
   {
   printf("\n 1.Insert\n");
   printf("\n 2.Delete\n");
   printf("\n 3.Search\n");
   printf("\n 4.Exit\n");
   printf("\n 5.Option=");
   scanf("%d",&option);
   switch(option)
   {
   case 1 :printf(" Item:");
   	  scanf("%d",&item);
   	  enque(item);
   	  break;
   	  
   case 2 :item=deque();
   	  printf(" Item=%d\n",item);
   	  break;
   	  
   case 3 :printf(" Item to search:");
   	  scanf("%d",&item);
   	  ans=search(item);
   	  if(ans!=0)
   	  printf(" %d found at %d\n",item,ans);
   	  else
   	  {
   	  printf(" not found\n");
   	  }
   	  break;
   	  
   case 4 :exit(1);
   }
   }
   while(1);
   }
 
 
 //function to insert an item in circularqueue 
   void enque(int item)
   {
    int t;
    t=(rear+1)%size;
    if(t==front)
     {
       printf(" Queue is full\n");
       exit(1);
     }
    else
      { 
       rear=t;
       que[rear]=item;
      }
   }
   
   
//function to delete an item in queue      
 int deque()
 {
    if(front==rear)
     {
      printf(" Queue is empty\n");
      exit(1);
     } 
    front=(front+1)%size;
    return que[front];
 }
 
 
 //fuction to search an item in circularqueue
 int search(int item)
 {
 int t1,t2;
 t1=front,t2=rear;
 t1=(t1+1)%size;
  while(t1!=t2 && que[t1]!=item)
	{
	t1=(t1+1)%size;
	}
 if(front==rear)
   {
     printf("Queue is empty");
     return 0;
   }  
 else if (que[t1]==item)
 {
  return t1;
 }
 else 
 {
  return 0;
 }
 }
   
   
   
   
   
   
   
      
   
   
   
   
   
   
   
   
   
   
   
   
   	  
   	  
   	  
   	  
   	  
   	  
   	  
   	  
   	  
   	  
   	  
   	  
