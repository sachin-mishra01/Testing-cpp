#include<bits/stdc++.h>
using namespace std;

int dot_product(vector<int>&arr1,vector<int>&arr2){
    int ans=0;
    for(int i=0;i<arr1.size();i++){
        ans=ans+arr1[i]*arr2[i];
    }
    return ans;
}

int main(){
    int m1,n1,m2,n2;
    cout<<"Enter the dimensions of matrix1 :";
    cin>>m1>>n1;
    vector<vector<int>>mat1(m1,vector<int>(n1));
    cout<<"Enter the dimensions of matrix2: ";
    cin>>m2>>n2;
    vector<vector<int>>mat2(m2,vector<int>(n2));
    cout<<"Enter the elements of first matrix: "<<endl;
    for(int i=0;i<m1;i++){
        for(int j=0;j<n1;j++){
            cin>>mat1[i][j];
        }
    }

    cout<<"Enter the elements of second matrix: "<<endl;
    for(int i=0;i<m2;i++){
        for(int j=0;j<n2;j++){
            cin>>mat2[i][j];
        }
    }
    vector<vector<int>>ans(m1,vector<int>(n2));
    int row=0;
    for(auto arr1:mat1){
        int i=0;
        while(i<n2){
            vector<int>arr2(m2);
            for(int j=0;j<m2;j++){
                arr2[j]=mat2[j][i];
            }
            ans[row][i]=dot_product(arr1,arr2);
            i++;
        }
        row++;
    }

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}