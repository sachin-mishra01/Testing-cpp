#include<iostream>
#include<vector>
using namespace std;
int max(vector <int>& nums ,int max=0)
{
 for(int i=0;i<nums.size();i++){
    if(max<nums[i]){
        max=nums[i];}
 }
 return max;
}
int main()
{
   vector<int> vec ={14,15,78,42,159,546,75,12,0,11};
   cout<<max(vec);
   return 1;
}
