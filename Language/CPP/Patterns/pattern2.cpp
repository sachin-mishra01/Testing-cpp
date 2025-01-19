#include<iostream>
using namespace std;

void pattern1(int l)
    {
        for(int i=0;i<l;i++)
        {
            for(int j=0 ;j<i;j++)
            {
            cout<<"*";
            }
            cout<<endl;
        }
    }
int main(){
    int n;
    cout<<"Enter the size :";
    cin>>n;
    pattern1(n);
    return 0;
}