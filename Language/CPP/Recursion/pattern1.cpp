#include<iostream>
using namespace std;
int pattern(int n)
{
    if(n==0)
    return 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cout<<"Enter the no. of row."<<endl;
    cin>>n;
    pattern(n);
    return 0;
}