#include <iostream>
using namespace std;

struct Node
{
    int info;
    struct Node *next;
};
typedef struct Node Nodetype;
Nodetype *head;

void INSERT_AT_BEGINNING(int item)
{
    Nodetype *newnode = new Nodetype;
    newnode->info = item;
    if (head == NULL)
    { // if node is empty
        head = newnode;
        newnode->next = NULL;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}

void INSERT_AT_LAST(int item)
{
    Nodetype *temp = new Nodetype;
    Nodetype *newnode = new Nodetype;
    if (head == NULL)
    {
        head = newnode;
        newnode->next = NULL;
        newnode->info = item;
    }
    else
    {
        temp = head;
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
    Nodetype *temp = new Nodetype;
    Nodetype *temp1 = new Nodetype;
    if (head == NULL)
    {
        cout << "Nothing to delete";
    }
    else if (head->next == NULL)
    {
        temp = head;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp1 = temp->next;
        temp->next = NULL;
        delete temp1;
    }
}

void DELETE_AT_BEGINNING()
{
    Nodetype *temp = new Nodetype;

    if (head == NULL)
    { // if empty
        cout << "NOTHING TO DELETE\n";
    }
    else if (head->next == NULL)
    { // if it has only one node
        temp = head;
        temp->next = NULL;
        delete temp;
    }
    else
    { // if not empty
        temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
}

void INSERT_AT_K_POSITION(int item, int position)
{
    Nodetype *temp = new Nodetype;
    Nodetype *newnode = new Nodetype;
    Nodetype *temp1 = new Nodetype;
    newnode->info = item;
    if (head == NULL)
    { // empty
        if (position == 1)
        {
            head = newnode;
            newnode->next = NULL;
        }
        else
        {
            cout << "INVALID POSITION\n";
        }
    }
    else
    { // non-empty case
        int count = 0;
        temp = head;
        while (temp->next != NULL)
        {
            ++count;
            temp = temp->next;
        }
        if (position <= count)
        {
            for (int i = 1; i < position - 1; i++)
            {
                temp = temp->next;
            }
            temp1 = temp->next;
            temp->next = newnode;
            newnode->next = temp1;
        }
        else
        {
            cout << "OUT OF INDEX\n";
        }
    }
}

void DELETE_AT_K_position(int position)
{
    Nodetype *temp = new Nodetype;
    Nodetype *temp1 = new Nodetype;
    if (head == NULL)
    {
        cout << "NOTHING TO DELETE\n";
    }
    else
    {
        int count = 0;
        temp = head;
        while (temp->next != NULL)
        {
            ++count;
            temp = temp->next;
        }
        if (position <= count)
        {
            for (int i = 1; i < position - 1; i++)
            {
                temp = temp->next;
            }
            temp1 = temp->next;
            temp->next = temp1->next;
            delete temp1;
        }
    }
}

void DISPLAY()
{
    Nodetype *temp = new Nodetype;
    temp = head;
    if (head == NULL)
    {
        cout << "NOTHING TO DISPLAY\n";
    }
    else
    {
        while (temp!= NULL)
        {
            cout << "---| " << temp->info << " |"
                 << "NEXT "
                 << " |----";
            temp = temp->next;
        }
    }
}

int main()
{
    int choice, item, position;
    while (1)
    {
        cout << "\nPRESS 1 to insert node at first position\n";
        cout << "PRESS 2 to delete node at first position\n";
        cout << "PRESS 3 to display the single linked list\n";
        cout << "PRESS 4 to exit the program\n";
        cout << "PRESS 5 to insert node at last position\n";
        cout << "PRESS 6 to delete node at last position\n";
        cout << "PRESS 7 to insert at specified position\n";
        cout << "PRESS 8 to delete at specified position\n";

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "enter the element to insert\n";
            cin >> item;
            INSERT_AT_BEGINNING(item);
            break;

        case 2:
            DELETE_AT_BEGINNING();
            break;

        case 3:
            DISPLAY();
            break;

        case 4:
            cout << "Exiting the program\n";
            exit(0);
            break;

        case 5:
            cout << "enter the data to be inserted at last element\n";
            cin >> item;
            INSERT_AT_LAST(item);
            break;

        case 6:
            DELETE_AT_LAST();
            break;

        case 7:
            cout << "enter the position to insert the element\n";
            cin >> position;
            cout << "insert the item to be inserted\n";
            cin >> item;
            INSERT_AT_K_POSITION(item, position);
            break;

        case 8:
            cout << "enter the position to delete the element\n";
            cin >> position;
            DELETE_AT_K_position(position);
            break;

        default:
            cout << "INVALID CHOICE\n";
        }
    }

    return 0;
}