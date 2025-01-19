#include<iostream>
#include "succ.cpp"
using namespace std;

bool prime(int n, int d)
{
    if(n==1||n==0) return false;
    if(d<= (n/2))           //d=3   n=8
    {   if(n%d!=0)
         prime(n,succ(d));
        else
        return false;      
    }
    return true;
}
int main()
{
    int n;
    cout<<"Enter the number :";
    cin>>n;
    cout<<prime(n,2); 
    return 0;
}