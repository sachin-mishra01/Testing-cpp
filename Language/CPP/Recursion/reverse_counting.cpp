#include<iostream>
using namespace std;

void reverse_counting(int n)
{
    if(n==1)
    {
        cout<<"1\n";
        return ;
    }
        cout<<n<<" ";
        reverse_counting(n-1);
}
int main()
{
    int num;
    cout<<"Enter the number :";
    cin>>num;
    reverse_counting(num);
    return 0;
}