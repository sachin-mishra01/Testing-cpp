#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void marks(vector<string> &vec, vector<char> &grade, int i = 0)
{
    if (i < vec.size())
    {
        int mark = stoi(vec[i]);
        if (mark >= 90 && mark <= 100)            //marks = 10000
        {
            grade.push_back('A');
        }
        else if (mark >= 70 && mark < 90)
        {
            grade.push_back('B');
        }
        else if (mark >= 50 && mark < 70)
        {
            grade.push_back('C');
        }
        else if (mark >= 30 && mark < 50)
        {
            grade.push_back('D');
        }
        marks(vec, grade, ++i);
    }
    else
        return;
}

int main()
{
    vector<string> vec;
    vector<char> grade;
    string str;
    ifstream in("marks.txt");
    while( getline(in, str))
    {
      vec.push_back(str);
    }
    in.close();
    cout << "Insert seccuesfully" << endl;
    
    marks(vec, grade);

    ofstream out("grade.txt");
    for (int i = 0; i < grade.size(); i++)
    {
        out << grade[i] << endl;
    }
    out.close();
    cout << "grade written seccuesfully" << endl;
    return 0;
}