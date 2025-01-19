#include<iostream>
#include<fstream>
using namespace std;
int main(){
    string st2;
    //Reading from the file...
    ifstream in("marks.txt");
    getline(in,st2);
    cout<<st2;

    return 0;
}