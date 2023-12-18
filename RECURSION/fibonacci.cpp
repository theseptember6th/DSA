#include <iostream>
using namespace std;

int fibonacci(int num)
{
    if (num == 1 || num == 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(num - 1) + fibonacci(num - 2);
    }
}

int main()
{
    int term;
    cout << "\nenter the nth term of fibonacci series\n ";
    cin >> term;

    for (int i = 1; i <= term; i++)
    {
        cout << " " << fibonacci(i) << " ";
    }

    return 0;
}