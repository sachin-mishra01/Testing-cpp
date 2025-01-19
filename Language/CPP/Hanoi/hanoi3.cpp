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

// Swap values of two integer variables
void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

// Iterative non-recursive Tower of Hanoi using a stack
void hanoi1(stack<Entry>& runtimeStack, int nDisks, int source, int spare, int destn) {
    // Push initial task onto the stack
    runtimeStack.push(Entry(nDisks, source, spare, destn, "initial"));

    while (!runtimeStack.empty()) {
        Entry current = runtimeStack.top();
        runtimeStack.pop();

        if (current.getNDisks() == 1) {
            // Base case: move one disk directly
            cout << "Move disk 1 from pole " << current.getSource() 
                 << " to pole " << current.getDestn() << endl;
        } else {
            // Unroll the recursive Tower of Hanoi steps for n > 1
            // Step 3: move n-1 disks from spare to destination
            runtimeStack.push(Entry(current.getNDisks() - 1, current.getSpare(), current.getSource(), current.getDestn(), "stmt3"));

            // Step 2: move the nth disk from source to destination
            cout << "Move disk " << current.getNDisks() << " from pole " << current.getSource() 
                 << " to pole " << current.getDestn() << endl;

            // Step 1: move n-1 disks from source to spare
            runtimeStack.push(Entry(current.getNDisks() - 1, current.getSource(), current.getDestn(), current.getSpare(), "stmt1"));
        }

        // Display the runtime stack after each move
        displayStack(runtimeStack);
    }
}

// Initialize Tower of Hanoi with an empty stack
void hanoi(int nDisks, int source, int spare, int destn) {
    assert(nDisks >= 1);
    stack<Entry> runtimeStack;  // Create a run-time stack
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
