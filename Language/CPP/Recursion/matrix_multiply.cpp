#include<iostream>
#include<bits/stdc++.h>
using namespace std; 

int main() {
    int m,n;
    cout<<"Enter the dimension of arr1 :";
    cin>>m>>n;
    int arr1[m][n];
     cout<<"Enter the element in matrix 1 :"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr1[i][j];
        }
    }
    int m1,n1;
    cout<<"Enter the dimension of arr2 :";
    cin>>m1,n1;
    int arr2[m1][n1];
    cout<<"Enter the element in matrix 2 :"<<endl;
    for(int i=0;i<m1;i++)
    {
        for(int j=0;j<n1;j++)
        {
            cin>>arr2[i][j];
        }
    }
    
    int ans[m][n1];
    cout<<"Product is :";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n1;j++)
        {
            ans[i][j]=((arr1[i][j]*arr2[i][j])+(arr1[i][j]*arr2[j][i]));
        }
    }
     for(int i=0;i<m;i++)
    {
        for(int j=0;j<n1;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}