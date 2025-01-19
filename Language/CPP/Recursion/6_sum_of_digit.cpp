#include<iostream>
#include "pred.cpp"
using namespace std;
int sumofnum(int n, int sum)
{
 if(n==0)
 {
    return sum; //base case
 }
 else{
    int rem= n%10;         //n=529    ->     rem=9     ->     sum=9      ->     n=52
    sum=sum+rem;           //n=52     ->     rem=2     ->     sum=9+2=11      ->     n=5
    n=n/10;                //n=5      ->     rem=5     ->     sum=11+5=16     ->n=0
    sumofnum(n, sum);      //n=0      ->     retrun sum=16
 }
}
int main()
{
    int n, result;
    cout<<"Enter the num = ";
    cin>>n;
    cout<<"Sum of digit of the given number is :" <<sumofnum(n,0);
    return 0;
}