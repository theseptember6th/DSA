#include <iostream>
using namespace std;

void Fibonacci(int num)
{
    int a = 0;
    int b = 1;

    for (int i = 0; i < num; i++)
    {
        cout << a << " ";
        int c = a + b;
        a = b;
        b = c;
    }
}

int main()
{
    int term;
    cout << "\nenter the nth term of your fibonacci series: ";
    cin >> term;

    Fibonacci(term);

    return 0;
}