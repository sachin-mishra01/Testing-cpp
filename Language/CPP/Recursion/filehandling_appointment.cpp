#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string fortnight,str;
    int month,year;

    cout<<"enter the fortnight :";
    cin>>fortnight;
    cout<<"enter the month :";
    cin>>month;
    cout<<"enter the year :";
    cin>>year;

    ifstream in("appointments_sample.txt");
    ofstream out("result.txt");
    while(getline(in,str))
    {
        int d,m,y;

        stringstream ss(str);
        ss>>d>>m>>y;
    if(y<=2047&&y>=2022){
        if(y==year){
            if(m==month){
                if(fortnight =="first"){
                    if(d>0 && d<=15){
                        out<<str<<endl;
                    }}
                else{
                     if(d>15 && d<=31){
                        out<<str<<endl;
                    }} } } }}
    in.close();
    out.close();

    return 0;
}


































// int main()
// {
//     vector<string> vec;
//     vector<char> grade;
//     string str;
//     ifstream in("marks.txt");
//     int n;
//     while( getline(in, str))
//     {
//       vec.push_back(str);
//     }
//     in.close();
//     cout << "Insert seccuesfully" << endl;
//     marks(vec, grade);

//     ofstream out("grade.txt");
//     for (int i = 0; i < grade.size(); i++)
//     {
//         out << grade[i] << endl;
//     }
//     out.close();
//     cout << "grade written seccuesfully" << endl;
//     return 0;
// }