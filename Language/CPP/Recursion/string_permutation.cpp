#include<iostream>
#include<vector>
#include<string>
using namespace std;

template <typename T>
    void permutation(vector<T> &vec, vector<vector<T>> &ans, int index)
    {
    if(index >= vec.size()){            //base case
        ans.push_back(vec);
        return;
    }
    for(int i=index;i<vec.size();i++){
        swap(vec[index],vec[i]);
        permutation(vec,ans,index+1);
        swap (vec[index],vec[i]);
    }
}
template <typename T>
 void permute(vector<T>& vec1){
    vector<vector<T>> ans;
    int index = 0,i=0;
    permutation(vec1,ans,index);
    
    while(i!=ans.size()){
        for(int j=0;j<vec1.size();j++){
            cout<<ans[i][j];
        }    
        i++;
        cout<<endl;
    }
}
int main()
{
    
    vector<char> vec;
    //vector<int> arr={1,2,3,4};
    string str;
    cout<<"Enter the string :";
    cin>>str;
    for(int i=0; i<str.size(); i++)
    {
        vec.push_back(str[i]);
    }
    permute(vec);
    return 0;
}