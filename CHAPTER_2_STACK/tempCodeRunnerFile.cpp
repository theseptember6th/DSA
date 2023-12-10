#include<iostream>
#include<cstring>
using namespace std;
#define size 10

struct stacks {
    int stack[size];
    int top = -1;
};

typedef struct stacks st;

int pop(st* p) {
    if (p->top == -1) {
        cout << "\nstack is empty\n";
       return 0;
    }
    else {
        int deleted = p->stack[p->top];
        p->top--;
        return deleted;
    }
}

void push(st* p, int item) {
    if (p->top == size - 1) {
        cout << "\n stack full\n";
        
    }
    else {
        p->top++;
        p->stack[p->top] = item;
    }
}

void display(st* p) {
    if (p->top == size - 1) {
        cout << "\n stack full\n";
        
    }
    else{
    cout<<"\ndisplaying\n\n\n";
    for (int i = 0; i <= p->top; i++) {
        cout << " \t" << p->stack[i] << "\t ";
    }
    cout<<"\n\n\n";
    }
}

int main() {
    st* p = new st; // Allocate memory for the stack

    int choice;
    while (1) {
        cout << "\nPress 1 to pop\n";
        cout << "\nPress 2 to push\n";
        cout << "\nPress 3 to display\n";
        cout << "\nPress 4 to exit\n";
        cin >> choice;
        

        switch (choice) {
        case 1:
            int x=pop(p);
            if(x){
            cout << "\nthe deleted item is " << x;
            }
            break;

        case 2:
            int value;
            cout << "\n enter the value to be pushed\n";
            cin >> value;
            push(p, value);
            break;

        case 3:
            display(p);
            break;

        case 4:
            cout << "\n exiting......\n";
            delete p; // Free the allocated memory
            exit(1);
            break;

        default:
            cout << "\n invalid choice.....\n";
            break;
        }
    }

    return 0;
}
