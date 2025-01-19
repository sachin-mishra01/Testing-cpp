#include <iostream>
using namespace std;

void hanoi(int nDisk, int source, int spare, int dest)
{
    if (nDisk == 1)
    {
        cout << "Move disk from pole " << source << " to pole" << dest << endl;
    }
    else
    {
        hanoi(nDisk - 1, 1, 3, 2);
        cout << "Move disk from pole " << source << " to pole" << dest << endl;
        hanoi(nDisk - 1, 2, 1, 3);
    }
}
int main()
{
    int nDisk;
    cout << "Enter the no of disk :";
    cin >> nDisk;
    hanoi(nDisk, 1, 2, 3);
    return 0;
}