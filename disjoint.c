#include<stdio.h>
#include<stdlib.h>
//structure to represent an object of a set in linked representation
typedef struct{
              int value;
              struct rep *repptr;//pointer to header node of the list
              struct node *next;
              }node;
//structure to represent header node of linked representation of list        
typedef struct{
              node *head;
              node *tail;
              }rep;
//structure to store key and object node pointer
typedef struct{
              int key;
              node *obj_node_ptr;
              struct nodaddr*next;
              }nodaddr;
              nodaddr*ndr=0;//list to store keys and object node pointers
              
   //function to create a set for an object   
  void makeset(int a)
     { //create an object node pointer
      nodaddr *t=(nodaddr*)malloc(sizeof(nodaddr));
      //create a new set
      rep *newset=(rep*)malloc(sizeof(rep));
      node *n=(node*)malloc(sizeof(node));
      //fill values
       n->value=a;
       n->repptr=newset;
       n->next=0;
       //initialize head and tail
       newset->head=newset->tail=n;
       //function to store object node pointer and key
        t->obj_node_ptr=n;
        t->key=a;
        t->next=ndr;
        ndr=t;
        }
        
//function to return pointer of the representative(header node)0 containing x
rep*find(int x)
  {
   nodaddr *t=ndr;
   while(t->key!=x && t!=0)
   t=t->next;
   return t->obj_node_ptr->repptr;
   }
   
//function to find union of two sets corresponding to objects given
void unionset(int key1,int key2)
{
 rep *set1, *set2;
 node *t1;
 set1=find(key1);
 set2=find(key2);
 if(set1==set2)
    printf("\n%d and %d belongs to same set\n",key1,key2);
 else
    {
    //changing the header pointer of objects of set2 to that of set1
    t1=set2->head;
    while(t1!=0)
    {
    t1->repptr=set1;
    t1=t1->next;
    }     
    set1->tail->next=set2->head;
    set1->tail=set2->tail;
    } //set the tail of set1 to tail of set2
    free(set2);
    }
//function to display a set
void display_set(int a)
   {
    rep *r;
    node *t;
    r=find(a);
    t=r->head;
    printf("set members containing %d:",a);
    while(t!=0)
      {
       printf("%d",t->value);
       t=t->next;
      }
    }
  void main()
   {
   makeset(10);
   makeset(20);
   makeset(30);
   makeset(40);
   makeset(50);
   printf("\nfind(10)=%x",find(10));
   printf("\n");
   printf("\nfind(20)=%x",find(20));
   printf("\n");
   printf("\nfind(30)=%x",find(30));
   printf("\n");
   printf("\nfind(40)=%x\n",find(40));
   printf("\n");
   unionset(10,20);
   display_set(10);
   printf("\nafter union of 10 & 20 find(20)=%x\n",find(20));
   unionset(30,40);
   display_set(30);
   printf("\nafter union of 30 & 40 find(40)=%x\n",find(40));
   unionset(20,40);
   display_set(40);
   printf("\nafter union of 10 & 30 find(40)=%x\n",find(40));
   }
   
     
    
    
  
