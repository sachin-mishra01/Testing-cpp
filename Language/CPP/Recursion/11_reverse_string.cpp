#include<iostream>
#include<string>
#include<vector>
using namespace std;

string reverse(string str)
{
    if(str.size()==0)
    {
        return "";
    }
    return reverse(str.substr(1,str.size())) + str[0];
}

int main()
{
    string str;
    cout<<"Enter the string :";
    cin>>str;
    cout<<reverse(str);
    return 0;
}