#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Entry class to represent a single recursive call's parameters
class Entry {
public:
    int nDisks;
    int source;
    int spare;
    int destn;

    Entry(int nDisks, int src, int sp, int dest)
        : nDisks(nDisks), source(src), spare(sp), destn(dest) {}
};

// Function to display the current recursion stack
void displayStack(stack<Entry> tempStack) {

    // stack<Entry> tempStack = runtimeStack; // Copy the stack for display
    cout << "Current Stack Content:" << endl;
    while (!tempStack.empty()) {
        Entry e=tempStack.top();
        tempStack.pop();
         cout << "nDisks: " << e.nDisks
             << ", Source: " << e.source
             << ", Spare: " << e.spare
             << ", Destn: " << e.destn << endl;
    }
    cout << "----------------------------" << endl;
}

// Recursive Tower of Hanoi function
void hanoiRecursive(stack<Entry>& runtimeStack, int nDisks, int source, int spare, int destn) {
    runtimeStack.push(Entry(nDisks, source, spare, destn));
    displayStack(runtimeStack); // Display stack after pushing the current call

    if (nDisks == 1) {
        // Base case: move one disk
        cout << "Move disk from pole " << source << " to pole " << destn << endl;
    } else {
        // Recursive case
        hanoiRecursive(runtimeStack, nDisks - 1, source, destn, spare); // Move n-1 disks to spare
        cout << "Move disk from pole " << source << " to pole " << destn << endl; // Move nth disk
        hanoiRecursive(runtimeStack, nDisks - 1, spare, source, destn); // Move n-1 disks to destination
    }

    runtimeStack.pop();
    displayStack(runtimeStack); // Display stack after popping the current call
}

int main() {
    int nDisks;
    cout << "Enter the number of disks: ";
    cin >> nDisks;

    stack<Entry> runtimeStack;
    hanoiRecursive(runtimeStack, nDisks, 1, 2, 3); // Call the recursive function
    return 0;
}
