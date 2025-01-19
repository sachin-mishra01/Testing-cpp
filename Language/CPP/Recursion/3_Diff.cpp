#include<iostream>
#include"pred.cpp"
using namespace std;
// Assumption :- a>=b
int Diff(int a, int b,int count=0)
{
 if(a==b) return count;  // base case
 else return Diff(a, pred(b),count++);
}
int main()
{
    int a,b;
    cout<<"Enter the two Integer :-";
    cin>>a>>b;
    cout<<"The difference between given numbers is "<<Diff(a,b);
    return 0;
}