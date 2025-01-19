#include<iostream>
using namespace std;
int hcf(int a, int b)
{
    if(b==0)
     return a;
    return hcf(b,a%b);
}
int main()
{
    int a, b;
    cout<<"Enter the value of a and b =";
    cin>>a>>b;
    cout<<hcf(a,b);
    return 1;
}