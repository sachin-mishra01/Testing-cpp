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

    void display() const {
        cout << "nDisks: " << nDisks << ", Source: " << source
             << ", Spare: " << spare << ", Destn: " << destn
             << ", ReturnAddr: " << returnAddr << endl;
    }
};

void displayStack(const stack<Entry>& stk) {
    stack<Entry> tempStack = stk;
    cout << "Displaying all elements in the stack:" << endl;
    while (!tempStack.empty()) {
        tempStack.top().display();
        tempStack.pop();
    }
    cout << "---------------------------" << endl;
}

void hanoi1(stack<Entry>& Stack, int nDisks, int source, int spare, int destn) {
    Stack.push(Entry(nDisks, source, spare, destn, "Undefined"));
    cout << "on entry to hanoi1" << endl;
    displayStack(Stack);

stmt1:
    if (nDisks == 1) {
        cout << "Move disk 1 from pole " << source << " to pole " << destn << endl;
    } else {
        Stack.pop();
        Stack.push(Entry(nDisks, source, spare, destn, "stmt2"));
        displayStack(Stack);
        swap(spare, destn);

    stmt2:
        cout << "Move disk " << nDisks << " from pole " << source << " to pole " << destn << endl;

        Stack.pop();
        Stack.push(Entry(nDisks, source, spare, destn, "stmt3"));
        displayStack(Stack);
        swap(source, spare);
        goto stmt1;
    }

stmt3:
    if (!Stack.empty()) {
        cout << "On exit from hanoi1" << endl;
        string jumpTo = Stack.top().returnAddr;
        Stack.pop();
        displayStack(Stack);
        if (jumpTo == "stmt1")
            goto stmt1;
        else if (jumpTo == "stmt2")
            goto stmt2;
    }
}

void hanoi(int nDisks, int source, int spare, int destn) {
    assert(nDisks >= 1);
    stack<Entry> Stack;
    hanoi1(Stack, nDisks, source, spare, destn);
}

int main() {
    int nDisks;
    cout << "Enter the number of disks: ";
    cin >> nDisks;

    hanoi(nDisks, 1, 2, 3);

    return 0;
}
