#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node*next;
 
};
struct node*head=NULL,*tail=NULL;
int count=0;


//insertion at begining
    void insertatbeg()
    { 
    struct node*newnode;
    newnode=(struct node*) malloc(sizeof(struct node));
    printf("enter the no u want to insertion at beginning-");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode ->next=head;
    head= newnode;
    tail->next=head;
    }

    //insertion at end
    void insertatend()
    { 
    struct node*newnode;
    newnode=(struct node*) malloc(sizeof(struct node));
    printf("enter the no u want to insertion at beginning-");
    scanf("%d", &newnode->data);
    newnode->next=NULL;
    tail->next=newnode;
    tail= newnode;
    tail->next=head;
    }

    //insertion at position
    void insertatpos()
    {
     struct node*newnode,*temp=head;
     int pos,i=1;
        printf("enter the position u want to enter-");
        scanf("%d",&pos);
        if (pos>count)
        {
           printf("invalid output\n");
        }
        else
        {
            while (i<pos){
                temp=temp->next;
                i++;
            }
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("enter data-");
            scanf("%d", &newnode->data);
            newnode->next=temp->next;
            temp->next = newnode;
             

        }

    }

    // delection from beginning
 void delfrombeg()
 {
    struct node *temp;
    temp=head;
    head=head->next;
    tail->next=head;
    free(temp);  
 }

 // delete  from end
    void delfromend()
    {
      struct node* temp=head;
       struct node* prev=NULL;
      while(temp->next!=head)
      {
      prev =temp;
      temp=temp->next;
      }   

    prev->next=head;
    tail=prev;
    free(temp);    
        
 }
 
 
  // reverse
  void reverse()
  {
    struct node*prev,*current,*nextnode;
    prev=NULL;
    current=head;
    nextnode=NULL;
    tail->next=NULL;
    while(current!=NULL){
       nextnode= current-> next;
       current->next=prev;
       prev=current;
       current=nextnode;
    }
    head=current;
    tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
     tail->next=head;
  }

int main()

{
    
    int choice=1 ;
    struct node*newnode,*temp;
    while(choice==1)
    {
     newnode= (struct node*) malloc(sizeof(struct node));
     printf("enter data-");
     scanf("%d", &newnode->data);
     newnode->next=0;

     if(head==0){
        head=tail=newnode;
        tail->next=head;
         }
         else{
          tail->next=newnode;
          tail=newnode;
           tail->next=head;
         }
           
          // if want to check
          //use tail->next->data
         printf("do you want to continue-");
         scanf("%d", &choice);

          }
     temp=head;
     printf(" elements of circular linked list are-\n");
     while(temp->next!=head)
{
 printf("%d ",temp->data);
 temp=temp->next;
 count++;

 }
 printf ("%d ",temp->data);
 count++;
printf("\ntotal node- %d\n",count);

  printf("\nDo you want to insert an element at the beginning? (1 = Yes, 0 = No): ");
    scanf("%d", &choice);

    if (choice == 1) {
        insertatbeg();
    }

    printf("\nDo you want to insert an element at the end? (1 = Yes, 0 = No): ");
    scanf("%d", &choice);

    if (choice == 1) {
        insertatend();
    }
 printf("\nlinked list after insertion-");
temp = head;
count=0;
while(temp->next!= head)
{
    printf("%d ",temp->data);
    temp = temp->next;
   count++;
}
printf ("%d ",temp->data);
 count++;
 printf("\n total nodes- %d\n",count);


  printf("\nDo you want to insert an element at the position? (1 = Yes, 0 = No): ");
    scanf("%d", &choice);
 
    if (choice == 1) {
        insertatpos();

    }
 
 
    printf("linked after  insertion at position -");
    temp=head;
    //count=0;
    while(temp->next!=head)
    {
        printf("%d ",temp->data);
        temp=temp->next;
        //count++;

    }
    printf("%d ",temp->data);
        //count++;
        //printf("\ntotal node%d\n",count);

        printf("\nDo you want to delete an element at the beginning? (1 = Yes, 0 = No): ");
    scanf("%d", &choice);

    if (choice == 1) {
        delfrombeg();

    }
    printf("\nelements after deletion are - ");
    temp =head;
    while(temp->next!=head)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
        
    printf("%d ",temp->data);

       printf("\nDo you want to delete an element at the end? (1 = Yes, 0 = No): ");
    scanf("%d", &choice);

    if (choice == 1) {
        delfromend();

    }
    printf("\nelements after deletion are - ");
    temp =head;
    while(temp->next!=head)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
        
    printf("%d ",temp->data);


     printf("\nDo you want to reverse the cll? (1 = Yes, 0 = No): ");
    scanf("%d", &choice);

    if (choice == 1) {
        reverse();

    }
    printf("\nelements after reverse are - ");
    temp =head;
    while(temp->next!=head)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
        
    printf("%d ",temp->data);
}