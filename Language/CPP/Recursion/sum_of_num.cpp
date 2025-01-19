#include<iostream>
#include "pred.cpp"
using namespace std;
int sumofnum(int n, int sum)
{
 if(n==0)
 {
    return sum;
 }
 else{
    sum=sum+n;
    sumofnum(pred(n), sum);
 }
}
int main()
{
    int n, result;
    cout<<"Enter the num = ";
    cin>>n;
    cout<<sumofnum(n,0);
    return 1;
}