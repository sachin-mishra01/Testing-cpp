#include<iostream>
using namespace std;
int fac(int n, int ans=1)
{
    if(n!=0)
        ans =n*fac(n-1);
    else    
    return ans;
}
int main()
{
    int n;
    cout<<"Enter the number :-";
    cin>>n;
    cout<<"The factorial of "<<n <<" is :-"<<fac(n);
    return 0;
}