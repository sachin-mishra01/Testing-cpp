#include<iostream>
#include<math.h>
using namespace std;

int root(int a, int b, int c)
{
    int r1=((-b+(pow(b,2)-4*a*c))/2*a);
    int r2=((-b-(pow(b,2)-4*a*c))/2*a);
    cout<<r1<<" "<<r2;

}
int main()
{
    int a,b,c;
    cout<<"Enter the coefficent of x2 :";
    cin>>a;
    cout<<"/nEnter the coefficent of x :";
    cin>>b;
    cout<<"/nEnter the constant:";
    cin>>c;
    root(a,b,c);
    return 0;
}