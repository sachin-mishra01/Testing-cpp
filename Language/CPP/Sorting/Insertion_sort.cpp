// Time complexsity of the selection sort is O(n^2).
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 void insertion_sort(int vec[], int size)
 {      int n=size;
    for(int i=0;i<n;i++)
    {
        int j=i;
       while (j>0 && vec[j-1]>vec[j])
        {
            swap(vec[j],vec[j-1]);
            j--;
        }
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
    insertion_sort(vec,n);
    for(int i=0;i<n;i++) cout<<vec[i]<<" ";
    return 0;
}
