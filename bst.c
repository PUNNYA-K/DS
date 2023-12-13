#include<stdio.h>
#include<stdlib.h>

 struct node
   {
   int data;
   struct node*lchild,*rchild;
    };
   void main()
   {
         struct node*insert(struct node*,int);
         struct node*delete(struct node*,int);
         int search(struct node*,int);
         void inorder(struct node*);
         int option,data,ans,item;
         struct node*root=(struct node*)0;
         do
          {
          printf("\n1.Insert\n");
          printf("\n2.Delete\n");
          printf("\n3.Search\n");
          printf("\n4.Traverse\n");
          printf("\nOption:");
          scanf("%d",&option);
          switch(option)      
          {
           case 1:
           	printf("Data:");
           	scanf("%d",&data);
           	root=insert(root,data);
           	break;
           case 2:
           	printf("Data:");
           	scanf("%d",&data);
           	root=delete(root,data);
           	break;
           case 3:
           	printf("Item to search:");
           	scanf("%d",&data);
           	ans=search(root,data);
           	if(ans!=0)
           	 printf("found");
           	else
           	 printf("not found");
           	break;	
           case 4:
           	inorder(root);
           	break;
           case 5:
           	exit(0);
          } 
          }
          while(1);
          }
         
          
          	

//function to insert an item in bst
struct node*insert(struct node*root,int data)
{
  struct node*par=(struct node*)0,*t,*troot=root;
  while(root!=(struct node*)0 && data!=root->data)
  {
   par=root;
   if(data<root->data)
    root=root->lchild;
   else 
    root=root->rchild;
   }
   
   if(root!=(struct node*)0)
   {
    printf("Duplicate");
    }
   else
    {
     t=(struct node*)malloc(sizeof(struct node));  
     t->data=data; //node creation
     t->lchild=t->rchild=(struct node*)0;
    if(par==(struct node*)0) //first node
      troot=t;
    else if(data<par->data)
      par->lchild=t;
    else
      par->rchild=t;
    }
    return troot;
   }
   
   //function to delete an item from bst
   struct node*delete(struct node*root,int data)
   {
    struct node*par=(struct node*)0,*t,*sucpar,*suc,*lchild,*rchild;
    t=root;
    while(root!=(struct node*)0 && data!=root->data)
     {
      par=root;
      if(data<root->data)
       root=root->lchild;
      else
       root=root->rchild;
      }
      if(root==(struct node*)0)
       printf("Not found\n");
      else
       {
       if(root->lchild==(struct node*)0 && root->rchild==(struct node*)0)//left node removal
         if(par==(struct node*)0)//root removal
          t=(struct node*)0;//null tree
         else if(data<par->data)
          par->lchild=(struct node*)0;
         else    
          par->rchild=(struct node*)0;
        else if(root->lchild==(struct node*)0 || root->rchild==(struct node*)0) //1child
         {
          if(par==(struct node*)0)//loop removal
          t=root->lchild==(struct node*)0 ? root->rchild:root->lchild;
          else if(data<par->data)
          par->lchild=root->lchild==(struct node*)0 ? root->rchild:root->lchild;
          else    
          par->rchild=root->lchild==(struct node*)0 ? root->rchild:root->lchild;
          }
        else //case of two children
         {
          //find inorder successor
          suc=root->rchild;
          sucpar=root;
          while(suc->lchild!=(struct node*)0)
          {
           sucpar=suc;
           suc=suc->lchild;
           }
           root->data=suc->data; //copy suc data to the node to be selected
           
           //removal of inorder successor
           if(suc->data<sucpar->data)
            sucpar->lchild=suc->lchild;
           else 
            sucpar->rchild=suc->rchild;
            root=suc;
            }
            }
    
            free(root);
            return t;//new root in case of 0 and 1 child
            }
           
            
      //function to search an item in bst
      int search(struct node*root,int data)
      {
       while(root!=(struct node*)0 && root->data!=data)
       {
        if(data<root->data)
         root=root->lchild;
        else
         root=root->rchild;
         }
        if(root==(struct node*)0)
         return 0;
        else 
         return 1;
         }
       
       
       //function to traverse bst
       void inorder(struct node*root)
       {
        if(root!=(struct node*)0)
        {
         inorder(root->lchild);//left visit
         printf("%d\t",root->data);//print root
         inorder(root->rchild);//right visit
         }
         }
     
          
          

