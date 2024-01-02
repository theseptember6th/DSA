#include <iostream>
using namespace std;

void enqueue(int *queue, int *rear, int *front, int size)
{
    int item;
    if (*rear == size - 1)
    {
        cout << "Stack full\n";
    }
    else
    {
        cout << "enter the item to be inserted\n";
        cin >> item;
        (*rear)++;
        queue[*rear] = item;
    }
}

void dequeue(int *queue, int *rear, int *front)
{
    if (*rear < *front)
    {
        cout << "Stack empty ..nothing to remove\n";
    }
    else
    {
        int temp;
        int x = queue[*front];
        for (int i = *front + 1; i <= *rear; i++)
        {
            if (x > queue[i])
            {
                temp = i; // x stores the minimum element
                x = queue[i];
            }
        }
        for (int i = temp; i < *rear; i++)
        {
            queue[i] = queue[i + 1];
        }
        cout << "the deleted item is " << x << "\n";
        (*rear)--;
    }
}

void display(int *queue, int *rear, int *front)
{
    for (int i = *front; i <= *rear; i++)
    {
        cout << queue[i] << " ";
    }
}
int main()
{
    int size;
    int rear = -1;
    int front = 0;
    cout << "enter the size of the queue\n";
    cin>>size;
    int *queue = new int[size];
    int choice;
    while (1)
    {
        cout << "PRESS 1 to insert\n";
        cout << "PRESS 2 to delete\n";
        cout << "PRESS 3 to display\n";
        cout << "PRESS 4 to exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            enqueue(queue, &rear, &front, size);
            break;

        case 2:
            dequeue(queue, &rear, &front);
            break;

        case 3:
            display(queue, &rear, &front);
            break;

        case 4:
            cout << "DELETING THE QUEUE.....\n";
            delete[] queue;
            cout << "EXITING...\n";
            exit(0);
            break;

        default:
            cout << "Invalid choice..\n";
            break;
        }
    }

    delete[] queue;

    return 0;
}