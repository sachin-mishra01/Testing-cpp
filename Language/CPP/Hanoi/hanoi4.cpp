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
    Entry(int nDisks, int src, int sp, int dest, string retAddr)
        : nDisks(nDisks), source(src), spare(sp), destn(dest), returnAddr(retAddr) {}

    int getNDisks() const { return nDisks; }
    int getSource() const { return source; }
    int getSpare() const { return spare; }
    int getDestn() const { return destn; }
    string getReturnAddr() const { return returnAddr; }

    void display() const {
        cout << "nDisks: " << nDisks << ", Source: " << source
             << ", Spare: " << spare << ", Destn: " << destn
             << ", ReturnAddr: " << returnAddr << endl;
    }
};

void displayStack(const stack<Entry>& stk) {
    stack<Entry> tempStack = stk;
    cout << "runtimeStack:" << endl;
    while (!tempStack.empty()) {
        tempStack.top().display();
        tempStack.pop();
    }
    cout << "------------End of Stack-------------" << endl;
}

void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

void hanoi1(stack<Entry>& runtimeStack, int nDisks, int source, int spare, int destn) {
    int recursiveCallNo = 0;
stmt1:
    //runtimeStack.push(Entry(nDisks, source, spare, destn, "undefined"));
    cout << "On entry to hanoi1, recursive call no: " <<  recursiveCallNo <<  endl;
    cout << "source: " << source << " spare: " << spare << " destn " << destn;
    displayStack(runtimeStack);

    if (nDisks == 1) {
        cout << "Move a disk from pole " << source << " to pole " << destn << endl;
        goto stmt3;
    }

    //runtimeStack.pop();
    runtimeStack.push(Entry(nDisks, source, spare, destn, "stmt2"));
    ++recursiveCallNo;
    cout <<  "Just before recursive call no: " << recursiveCallNo;
    displayStack(runtimeStack);
    nDisks -= 1;
    swap(destn, spare);

    goto stmt1;

stmt2:
    cout << "Move a  disk " << " from pole " << source << " to pole " << destn << endl;

    //runtimeStack.pop();
    cout << "Just before pushing for second call, ";
    runtimeStack.push(Entry(nDisks, source, spare, destn, "stmt3"));
    displayStack(runtimeStack);
    nDisks -= 1;
    swap(source, spare);
    ++recursiveCallNo;
    goto stmt1;

stmt3:
    if (!runtimeStack.empty()) {
        cout << "Before pop off, on exit from recursive call no:  " << recursiveCallNo <<  endl;
        displayStack(runtimeStack);
        string jumpTo = runtimeStack.top().getReturnAddr();
        nDisks = runtimeStack.top().getNDisks();
        source = runtimeStack.top().getSource();
        spare = runtimeStack.top().getSpare();
        destn = runtimeStack.top().getDestn();
        runtimeStack.pop();
        cout << "After pop off, on exit from recursive call no: " <<  recursiveCallNo <<  endl;
        displayStack(runtimeStack);

        if (jumpTo == "stmt2")
            goto stmt2;
        else if (jumpTo == "stmt3")
                 goto stmt3;
    }
}

void hanoi(int nDisks, int source, int spare, int destn) {
    assert(nDisks >= 1);
    stack<Entry> runtimeStack;
    hanoi1(runtimeStack, nDisks, source, spare, destn);
}

int main() {
    int nDisks;
    cout << "Enter the number of disks: ";
    cin >> nDisks;

    hanoi(nDisks, 1, 2, 3);

    return 0;
}
