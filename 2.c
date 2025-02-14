#include<stdio.h>
#include<stdlib.h>
#define mapsize 10000
typedef struct map
{
    int key;
    int data;
    struct map* next;
}map;
map* hash_map[mapsize]={NULL};
int hashfunction(int key)
{
    return key%mapsize;
}
map* create(int key,int data)
{
    map* new=(map*)malloc(sizeof(map));
    new->key=key;
    new->data=data;
    new->next=NULL;
    return new;
}

map* create_map(int key,int data)
{
    int hashvalue=hashfunction(key);
    map* new=create(key,data);
    if(hash_map[hashvalue]==NULL)
    {
        hash_map[hashvalue]=new;
    }
    else
    {
        map* temp=hash_map[hashvalue];
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
    }
}

void display()
{
    int i;
    for(i=0;i<mapsize;i++)
    {
        printf("index: %d-> ",i);
        map* temp=hash_map[i];
        while(temp!=NULL)
        {
            printf("%d %d-> ",temp->key,temp->data);
            temp=temp->next;
        }
        printf("NULL")
;       printf("\n");
    }
}

int main()
{
    create_map(10,20);
    create_map(10,21);
    create_map(11,22);
    create_map(11,23);
    create_map(12,24);
    create_map(22,20);
    create_map(19,24);
    display();

    return 0;
}