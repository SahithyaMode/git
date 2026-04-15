    //printf("enter the choice 1.add_begin 2. add_end 3. add_pos 4.print 5.exit 6.free_list 7.search_node \n");

/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>
typedef struct single
{
    int data;
    struct single *next;
}sll;
struct single * add_begin(struct single*head)
{
    struct single *newnode=(struct single*)malloc(sizeof(struct single));
    if(newnode==NULL)
    {
        free(newnode);
      return head;
    }
    printf("enter the data;\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
    return head;
}
struct single * add_end(struct single*head)
{
    struct single *newnode=(struct single*)malloc(sizeof(struct single));
    if(newnode==NULL)
    {
        perror("malloc");
        return head;
    }
    printf("enter the data;\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        struct single *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return head;
}
struct single * add_pos(struct single*head)
{
    struct single *newnode=(struct single*)malloc(sizeof(struct single));
    if(newnode==NULL)
    {
        perror("malloc");
        return head;
    }
    printf("enter the data;\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    int pos;
    printf("enter the pos:\n");
    scanf("%d",&pos);
    if(pos==1)
    {
        newnode->next=head;
        head=newnode;
    }
    else
    {
    struct single *temp=head;
    for(int i=1;i<pos-1 && temp!=NULL;i++)
    {
        
    temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("invalid position\n");
        free(newnode);
        newnode=NULL;
        return head;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    
    }
    return head;
}
void print(struct single *head)
{
    struct single *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void free_list(struct single *head)
{
    struct single *temp;
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
        temp=NULL;
    }
    printf("list freed\n");
}
int search_node(struct single *head,int key)
{
    int pos=1;
    struct single *temp;
    while(temp!=NULL)
    {
        if(temp->data==key)
        return pos;
        
        temp=temp->next;
        pos++;
        
    }
    return -1;
    
}
sll*sort_link(sll*head)
{
   sll*t1,*t2;
   for(t1=head;t1!=NULL;t1=t1->next)
   {
       for(t2=head;t2->next!=NULL;t2=t2->next)
       {
           if(t2->data > t2->next->data)
           {
               int temp=t2->data;
               t2->data=t2->next->data;
               t2->next->data=temp;
           }
       }
   }
   return head;
}
int main()
{
    struct single *head=NULL;
    int choice;
    while(1)
    {
    printf("enter the choice 1.add_begin 2. add_end 3. add_pos 4.print 5.exit 6.free_list 7.search_node 9.sort \n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:head=add_begin(head);
               break;
               case 2:head=add_end(head);
               break;
               case 3:head=add_pos(head);
               break;
               case 4:print(head);
               break;
               case 6:free_list(head);
               break;
               case 7:int pos = search_node(head,10);
               printf("pos:%d",pos);
               
               break;
               /*case 8:int pos;
               printf("enter the pos to enter:\n");
               scanf("%d",&pos);
               head=delete_pos(head,pos);
               break;*/
               case 9:head=sort_link(head);
               break;
               
               
        
        
    }
    }

}
