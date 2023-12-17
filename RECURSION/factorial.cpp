#include <iostream>
using namespace std;

int factorial(int num)
{
    if (num < 0)
    {
        cout << "INVALID";
        exit(0);
    }
    else if (num == 0)
    {
        return 1;
    }
    else
    {
        return num * factorial(num - 1);
    }
}

int main()
{
    int number;
    cout << "enter the factorial you want to find\n";
    cin >> number;

    int result = factorial(number);

    cout << "\nthe result is " << result;
    return 0;
}