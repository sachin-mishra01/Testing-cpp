#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

class entry{
    public :
        int disk,source,dest,spare;
        string retAddress;

        entry(int d,int sr, int sp, int dt ,string rtad) :  disk(d),source(sr),spare(sp),dest(dt),retAddress(rtad)
        {}
};

void display(stack<entry> &stk)
{
    stack<entry> tmpstk=stk;
    cout<<"Stack display "<<endl;
    while (!tmpstk.empty())
    { 
        entry e =tmpstk.top();
        tmpstk.pop();
        cout<<"disk :"<<e.disk<<"source :"<<e.source<<"spare :"<<e.spare<<"destintion :"<<e.dest<<"retureAddress :"<<e.retAddress<<endl; 
    }
    cout<<"----------------stack end-------------------"<<endl;
}

void hanoi1(stack<entry> &Stack,int disk,int source, int spare, int dest)
{
    Stack.push(entry(disk,source,spare,dest,"undifined"));
}

void hanoi(int disk,int source, int spare, int dest)
{
    assert(disk>=1);
    stack<entry> Stack;
    hanoi1(Stack,disk,source,spare,dest);
}
 int main()
 {
    int disk;
    cout<<"Enter the number of disk :";
    cin>> disk;

    hanoi(disk,1,2,3);
    return 0;
 }