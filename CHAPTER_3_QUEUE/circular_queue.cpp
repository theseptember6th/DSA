#include <iostream>
using namespace std;

void enqueue(int *queue, int *rear, int *front, int size)
{
    if (*front == (*rear + 1) % size)
    {
        cout << "queue full\n";
    }
    else
    {
        int item;
        *rear = (*rear + 1) % size;
        cout << "\nenter the item to insert: ";
        cin >> item;
        queue[*rear] = item;
    }
}

void dequeue(int *queue, int *rear, int *front, int size)
{
    if (*front == *rear)
    {
        cout << "queue empty\n";
    }
    else
    {

        *front = (*front + 1) % size;
        cout << "the deleted item is " << queue[*front];
    }
}

void display(int *queue, int *rear, int *front, int size)
{
    if (*rear == *front)
    {
        cout << "\nNothing to display..queue is empty\n";
    }
    else
    {
        for (int i = (*front + 1) % size; i != (*rear + 1) % size; i = (i + 1) % size)
        {
            cout << " " << queue[i] << " ";
        }
    }
}

int main()
{

    int size, choice;
    cout << "enter the size of the circular queue: ";
    cin >> size;
    int rear = size - 1, front = size - 1;
    int *queue = new int[size];

    while (1)
    {
        cout << "\nPRESS 1 to INSERT/ENQUEUE\t ";
        cout << "PRESS 2 TO DELETE/DEQUEUE\n";
        cout << "PRESS 3 TO DISPLAY\t";
        cout << "PRESS 4 TO EXIT \n";

        cin >> choice;

        switch (choice)
        {
        case 1:
            enqueue(queue, &rear, &front, size);
            break;

        case 2:
            dequeue(queue, &rear, &front, size);
            break;

        case 3:
            display(queue, &rear, &front, size);
            break;

        case 4:
            cout << "\nDELETING THE QUEUE";
            delete[] queue;
            cout << "\nEXITING.....";
            exit(0);

        default:
            cout << "INVALID CHOICE\n";
            break;
        }
    }
    delete[] queue;

    return 0;
}