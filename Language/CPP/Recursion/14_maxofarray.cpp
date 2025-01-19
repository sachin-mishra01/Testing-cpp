#include <iostream>
#include <vector>
using namespace std;

int max_array(vector<int> vec, int max, int i = 0, int index=0)
{
     if (i == vec.size())
    {
        return index;
    }
    if (vec[i]>max)
    {
       max = vec[i];
       index=i;
    }
        return max_array(vec, max, i+1, index);
}

int main()
{
    vector<int> vec = {12, 84, 23, 54, 32, 454};
    cout << max_array(vec, vec[0]);
    return 0;
}