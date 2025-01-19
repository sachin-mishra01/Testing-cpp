#include<iostream>
#include<vector>
using namespace std;

int binary_search1(vector<int> p, int tar, int st, int end){
    if(st<=end){
        int mid=(st+end)/2;
        if(p[mid]==tar)
            return mid;
        if(p[mid]<tar)
            return binary_search1(p,tar,mid+1,end);
        else
            return binary_search1(p,tar,st,mid-1);
    }
    else return -1;    
}

int binary_search(vector<int> p, int tar){
  return binary_search1(p,tar,0,p.size());
}

int main(){
    vector<int> arr={1,2,3,4,5,7,11,23,43};
    int target;
    cout<<"Enter the element for finding index : ";
    cin>>target;
    if(binary_search(arr,target)== -1)
        cout<<"The element is not in the array.";
    else
    cout<<"The index is : "<<binary_search(arr,target);
    return 0;
}