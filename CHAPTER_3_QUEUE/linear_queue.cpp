#include <iostream>
using namespace std;

void enqueue(int *queue, int *rear, int size)
{
    if (*rear == size - 1)
    {
        cout << "queue is full\n";
    }
    else
    {
        int item;
        (*rear)++;
        cout << "\nenter the item you want to enqueue/insert: ";
        cin >> item;
        queue[*rear] = item;
    }
}

void dequeue(int *queue, int *rear, int *front)
{
    if (*rear < *front)
    {
        cout << "queue is empty\n";
    }
    else
    {

        cout << "the deleted item is " << queue[*front];
        (*front)++;
    }
}

void display(int *queue, int *rear, int *front)
{
    if (*rear < *front)
    {
        cout << "nothing to display,queue is empty\n";
    }
    else
    {
        for (int i = *front; i <= *rear; i++)
        {
            cout << " " << queue[i] << " ";
        }
    }
}

int main()
{
    int rear = -1;
    int front = 0;
    int size;
    cout << "\nenter the size for the linear queue: ";
    cin>>size;
    int *queue = new int[size];
    int choice;
    while (1)
    {
        cout << "\nPRESS 1 to enqueue/insert \t";
        cout << "PRESS 2 to delete/dequeue\n";
        cout << "PRESS 3 to display\n";
        cout << "PRESS 4 to EXIT\n";

        cin >> choice;

        switch (choice)
        {
        case 1:
            enqueue(queue, &rear, size);
            break;

        case 2:
            dequeue(queue, &rear, &front);
            break;

        case 3:
            display(queue, &rear, &front);
            break;

        case 4:
            cout << "\nEXITING.......\n";
            cout << "DELETING QUEUE.....";
            delete[] queue;
            exit(0);
        }
    }
    delete[] queue;
    return 0;
}