#include <iostream>
using namespace std;

struct Node
{
    int info;
    struct Node *next;
};
typedef struct Node Nodetype;
Nodetype *top;



void INSERT_AT_LAST(int item)
{
    Nodetype *temp = new Nodetype;
    Nodetype *newnode = new Nodetype;
    if (top == NULL)
    {
        top = newnode;
        newnode->next = NULL;
        newnode->info = item;
    }
    else
    {
        temp = top;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
        newnode->info = item;
    }
}

void DELETE_AT_LAST()
{
    if (top == NULL)
    {
        cout << "Nothing to delete\n";
    }
    else if (top->next == NULL)
    {
        delete top;
        top = NULL;  // Set top to NULL after deleting the only node
    }
    else
    {
        Nodetype *temp = top;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}


void DISPLAY()
{
    Nodetype *temp = top;

    if (top == NULL)
    {
        cout << "EMPTY LIST\n";
        return;
    }

    while (temp != NULL)
    {
        cout << "---| " << temp->info << " |"
             << "NEXT "
             << " |----";
        temp = temp->next;
    }
    cout << endl;
}


int main()
{
    int choice, item, position;
    while (1)
    {
        cout<<"PRESS 1 to push\t\t";
        cout<<"PRESS 2 to pop\n";
        cout<<"PRESS 3 to display\t";
        cout<<"PRESS 4 to exit\n";

        cin >> choice;

        switch (choice)
        {
        

        case 1:
            cout << "enter the data to be inserted \n";
            cin >> item;
            INSERT_AT_LAST(item);
            break;

        case 2:
            DELETE_AT_LAST();
            break;

        case 3:
            DISPLAY();
            break;

        case 4:
            cout << "Exiting the program\n";
            exit(0);
            break;

        default:
            cout << "INVALID CHOICE\n";
        }
    }

    return 0;
}