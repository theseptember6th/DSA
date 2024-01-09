#include <stdio.h>

struct linked_list{
    int info;
    struct linked_list* next;


};

typedef struct linked_list mynode;
mynode *head;

void insertion_at_beg(int data){
    mynode *newnode;
    newnode = (mynode*)malloc(sizeof(mynode));
    newnode->info = data;
    if(head == NULL){
        head = newnode;
        newnode->next = NULL;
    }
    else{
    newnode->next = head;
    head = newnode;
    }
    
}
void display(){
    mynode *temp;
    temp = head;
    while(temp!=NULL){
        printf("%d",temp->info);
        temp= temp->next;
    }
}

int main(){
    int choice,data;
    int flag;
    here:
    printf("enter the choice");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
    printf("enter the data to enter");
    scanf("%d",&data);
        insertion_at_beg(data);
        
        break;
    case 2:
     display();
    
    default:
        break;
    }
    printf("DO YOU WANT TO CONTINUE\n");
    scanf("%d",&flag);
    if(flag){
       goto here;
    }
    
}