#include <iostream>
#include <vector>
using namespace std;

bool isSort(vector<int>p,int n){
    if(n==0||n==1)
        return true;
    return p[n-1]>=p[n-2] && isSort(p,n-1);
}

int main(){
    vector<int>arr={ 1,2,4,5,4,5};
    if(isSort(arr,arr.size()) ==1){
    cout<<"Array is sorted.";
    }
    else
    cout<<"Array is not sorted.";
    return 0;
}