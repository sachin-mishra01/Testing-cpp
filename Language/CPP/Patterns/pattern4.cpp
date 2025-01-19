#include<iostream>
using namespace std;

void pattern1(int l)
    {
        for(int i=1;i<l+1;i++)
        {
            for(int j=1 ;j<=i;j++)
            {
            cout<<i<<" ";
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