// Time complexsity of the selection sort is O(n^2).
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 void Bubble_sort(int vec[], int size)
 {      int n=size;
    for(int i=n-1;i>=1;i--)
    {
        int didswap=0;
        for(int j=0; j<=i-1;j++)
        {
            if(vec[j]>vec[j+1])
            {
            swap(vec[j],vec[j+1]);
            didswap=1;
            }
        }
        if(didswap==0) break;
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
    Bubble_sort(vec,n);
    for(int i=0;i<n;i++) cout<<vec[i]<<" ";
    return 0;
}
