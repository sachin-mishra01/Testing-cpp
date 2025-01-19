#include<iostream>
#include<vector>
using namespace std;

void permutation(vector<int> &vec,vector<vector<int>>& ans,int index)
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
void permute(vector<int>& vec){
    vector<vector<int>> ans;
    int index = 0,i=0;
    permutation(vec,ans,index);
    while(i!=ans.size()){
        for(int j=0;j<vec.size();j++){
            cout<<ans[i][j];
        }    
        i++;
        cout<<endl;
    }
    return;
}
int main()
{
    vector<int> vec;
    int n;
    cout<<"enter the number :";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        vec.push_back(i);
    }
    permute(vec);
    return 0;
}