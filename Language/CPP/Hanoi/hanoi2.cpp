#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

class Entry {
private:
    int nDisks;
    int source;
    int spare;
    int destn;
    string returnAddr;

public:
    // Constructor with initializer list
    Entry(int nDisks, int source, int spare, int destn, string retAddr)
        : nDisks(nDisks), source(source), spare(spare), destn(destn), returnAddr(retAddr) {}

    // Get functions
    int getNDisks() const { return nDisks; }
    int getSource() const { return source; }
    int getSpare() const { return spare; }
    int getDestn() const { return destn; }
    string getReturnAddr() const { return returnAddr; }

    // Display function for debugging and tracking
    void display() const {
        cout << "nDisks: " << nDisks << ", Source: " << source
             << ", Spare: " << spare << ", Destn: " << destn
             << ", ReturnAddr: " << returnAddr << endl;
    }
};

// Display the stack content without modifying it
void displayStack(const stack<Entry>& stk) {
    stack<Entry> tempStack = stk;
    cout << "Displaying all elements in the stack:" << endl;
    while (!tempStack.empty()) {
        tempStack.top().display();
        tempStack.pop();
    }
    cout << "---------------------------" << endl;
}

// Objective: Swap values of two integer variables
void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

// Non-recursive Tower of Hanoi using a stack
void hanoi1(stack<Entry>& runtimeStack, int nDisks, int source, int spare, int destn) {
stmt1:
    runtimeStack.push(Entry(nDisks, source, spare, destn, "stmt1"));
    cout << "On entry to hanoi1" << endl;
    displayStack(runtimeStack);

    if (nDisks == 1) {
        cout << "Move disk 1 from pole " << source << " to pole " << destn << endl;
    } else {
        runtimeStack.pop();
        runtimeStack.push(Entry(nDisks, source, spare, destn, "stmt2"));
        displayStack(runtimeStack);

        // Move n-1 disks from source to spare using destination as temporary storage
        swap(spare, destn);
        goto stmt1;
    }

stmt2:
    if (!runtimeStack.empty()) {
        // Move the nth disk from source to destination
        cout << "Move disk " << nDisks << " from pole " << source << " to pole " << destn << endl;

        // Move the n-1 disks from spare to destination using source as temporary storage
        runtimeStack.pop();
        runtimeStack.push(Entry(nDisks, source, spare, destn, "stmt3"));
        displayStack(runtimeStack);
        swap(source, spare);
        goto stmt1;
    }

stmt3:
    // Pop the stack for return from the recursive call
    if (!runtimeStack.empty()) {
        cout << "On exit from hanoi1" << endl;
        string jumpTo = (runtimeStack.top()).getReturnAddr();
        runtimeStack.pop();
        displayStack(runtimeStack);
        if (jumpTo == "stmt1")
            goto stmt1;
        else if (jumpTo == "stmt2")
            goto stmt2;
        else goto stmt3;
    }
}

// Initialize Tower of Hanoi with an empty stack
void hanoi(int nDisks, int source, int spare, int destn) {
    assert(nDisks >= 1);
    stack<Entry> runtimeStack;
    hanoi1(runtimeStack, nDisks, source, spare, destn);
}

int main() {
    int nDisks;
    cout << "Enter the number of disks: ";
    cin >> nDisks;

    // Initial call: move nDisks from pole 1 to pole 3 using pole 2 as a spare
    hanoi(nDisks, 1, 2, 3);

    return 0;
}
