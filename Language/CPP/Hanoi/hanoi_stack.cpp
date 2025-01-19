#include <iostream>
#include <stack>
#include <cassert>
#include <algorithm>
using namespace std;

class Entry {
public:
    int nDisks, source, spare, destn;
    string returnAddr;

    Entry(int nDisks, int src, int sp, int dest, string retAddr)
        : nDisks(nDisks), source(src), spare(sp), destn(dest), returnAddr(retAddr) {}
};

void hanoi(int nDisks, int source, int spare, int destn) {
    stack<Entry> Stack;
    Stack.push(Entry(nDisks, source, spare, destn, "Undefined"));

    while (!Stack.empty()) {
        Entry current = Stack.top();
        Stack.pop();

        if (current.nDisks == 1) {
            cout << "Move disk 1 from pole " << current.source << " to pole " << current.destn << endl;
        } else {
            // Push the steps in reverse order
            Stack.push(Entry(current.nDisks - 1, current.spare, current.source, current.destn, "stmt3"));
            Stack.push(Entry(1, current.source, current.spare, current.destn, "stmt2"));
            Stack.push(Entry(current.nDisks - 1, current.source, current.destn, current.spare, "stmt1"));
        }
    }
}

int main() {
    int nDisks;
    cout << "Enter the number of disks: ";
    cin >> nDisks;

    hanoi(nDisks, 1, 2, 3);

    return 0;
}
