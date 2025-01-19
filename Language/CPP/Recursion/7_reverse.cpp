#include<iostream>
#include "pred.cpp"
using namespace std;
int reverse(int n, int rev)
{
 if(n==0)
 {
    return rev;
 }
 else{
    rev= rev*10 + n%10;
    reverse(n/10, rev);
 }
}
int main()
{
    int n, result;
    cout<<"Enter the num = ";
    cin>>n;
    cout<<reverse(n,0);
    return 1;
}