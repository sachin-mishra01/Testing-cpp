// Time complexsity of the selection sort is O(n^2).
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 void Selection_sort(int vec[], int size)
 {      int n=size;
    for(int i=0;i<n-1;i++)
    {
        int mini=i;
        for(int j=i;j<n;j++)
        {
            if(vec[j]<vec[mini]) mini=j;
        }
        int temp=vec[i];
        vec[i]=vec[mini];
        vec[mini]=temp;
    }
 }

int main()
{
    int n;
    cout<<"Enter the size of Array :- ";
    cin>>n;
    int vec[n];
    for(int i=0;i<n;i++){
        cout<<i+1<<"th emelent :- ";
        cin>>vec[i];
        cout<<endl;
    }       
    Selection_sort(vec,n);
    for(int i=0;i<n;i++) cout<<vec[i]<<" ";
    return 0;
}
