#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node 
{
    int coefficiant;
    int power;
    struct node* next;
}node;

int findmaxpower(node** head1,node** head2)
{
    int maxpower=0;
    node* temp1=*head1;
    node* temp2=*head2;
    while(temp1!=NULL)
    {
        if( (temp1->power)>=maxpower)
        {
            maxpower=temp1->power;

        }
        temp1=temp1->next;
       
    }
    while(temp2!=NULL)
    {
        if( (temp2->power)>=maxpower)
        {
            maxpower=temp2->power;

        }
        temp2=temp2->next;
       
    }
    return maxpower;
}
node* create(int coefficiant,int power)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->coefficiant=coefficiant;
    newnode->power=power;
    newnode->next=NULL;
}

node* createnode(node** head,int coefficiant,int power)
{
    node* newnode=create(coefficiant,power);
    node* temp=*head;
    if(*head==NULL)
    {
        *head=newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

node* print(node** head)
{
    node* temp=*head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->coefficiant);
        printf("%d\n",temp->power);
        temp=temp->next;
    }
}

int main()
{
    node* head1=NULL;
    node* head2=NULL;
    int coefficiant,power=1;
    printf("taking the 1st polinomial\n");
    
    while(power!=0)
    {
        printf("Enter the coefficiant: ");
        scanf("%d",&coefficiant);
        printf("Enter the power value: ");
        scanf("%d",&power);
        createnode(&head1,coefficiant,power);

    }

    power=1;
    printf("First polinomial created\n");
    print(&head1);

    while(power!=0)
    {
        printf("Enter the coefficiant: ");
        scanf("%d",&coefficiant);
        printf("Enter the power value: ");
        scanf("%d",&power);
        createnode(&head2,coefficiant,power);

    }
    
    print(&head2);
    printf("second polinomial created\n");

    int maxpower=findmaxpower(&head1,&head2);
    printf("%d\n",maxpower);
    return 0;
}