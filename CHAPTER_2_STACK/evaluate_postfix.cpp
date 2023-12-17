#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int pop(int mainstack[], int *tp)
{
    if ((*tp) == -1)
    {
        cout << "\nstack is empty\n";
        return 0;
    }
    else
    {
        int value;
        value = mainstack[*tp];
        (*tp)--;
        return value;
    }
}

void push(int mainstack[], int *tp, int value, int size)
{
    if ((*tp) == size - 1)
    {
        cout << "stack full\n";
    }
    else
    {
        (*tp)++;
        mainstack[*tp] = value;
    }
}

void Evaluate(string pfix, int stack[])
{
    int top = -1;               // top for mainstack
    int length = pfix.length(); // you cant use strlen for strings...use string.length() or string.size()
    cout << length;
    int value1 = 0, value2 = 0;
    int check; // for pop
    for (int i = 0; i < length; i++)
    {
        if (isalpha(pfix[i]))
        {
            cout << "\nenter the value for the given alphabet  " << pfix[i] << ": ";
            cin >> stack[++top]; // to initialize top=0;
        }
        else
        {
            switch (pfix[i])
            {
            case '+':
                check = pop(stack, &top);
                if (check)
                {
                    value1 = check;
                }
                check = pop(stack, &top);
                if (check)
                {
                    value2 = check;
                }
                push(stack, &top, value2 + value1, length);
                break;

            case '-':
                check = pop(stack, &top);
                if (check)
                {
                    value1 = check;
                }
                check = pop(stack, &top);
                if (check)
                {
                    value2 = check;
                }
                push(stack, &top, value2 - value1, length);
                break;
            case '*':
                check = pop(stack, &top);
                if (check)
                {
                    value1 = check;
                }
                check = pop(stack, &top);
                if (check)
                {
                    value2 = check;
                }
                push(stack, &top, value2 * value1, length);
                break;

            case '/':
                check = pop(stack, &top);
                if (check)
                {
                    value1 = check;
                }
                check = pop(stack, &top);
                if (check)
                {
                    value2 = check;
                }
                push(stack, &top, value2 / value1, length);
                break;

            case '$':
            case '^':
                check = pop(stack, &top);
                if (check)
                {
                    value1 = check;
                }
                check = pop(stack, &top);
                if (check)
                {
                    value2 = check;
                }
                push(stack, &top, pow(value2, value1), length);
                break;
            }
        }
    }
}

int main()
{
    string postfix;
    int mainstack[postfix.length()]; // for efficient memory initialization
    cout << "\nenter the valid postfix expression: ";
    cin >> postfix;
    Evaluate(postfix, mainstack);

    cout << "\nafter evaluation the final result is " << mainstack[0];

    return 0;
}