#include <iostream>
using namespace std;
static int count = 0;
void towerofhanoi(int disks, char origin, char intermediate, char destination)
{

    if (disks > 0)
    {
        // origin to intermediate using destination
        towerofhanoi(disks - 1, origin, destination, intermediate);
        count++;
        cout << "step " << count << " move disk " << disks << " from " << origin << " to "
             << destination << "\n";

        // intermediate to destination using origin
        towerofhanoi(disks - 1, intermediate, origin, destination);
    }
}

int main()
{
    int disks;
    cout << "\nenter the initial number of disks: ";
    cin >> disks;
    towerofhanoi(disks, 'A', 'B', 'C');

    return 0;
}