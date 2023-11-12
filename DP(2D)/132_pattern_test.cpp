#include<bits/stdc++.h>
using namespace std;

bool find132pattern(vector<int>& nums) {
    int n = nums.size();
   vector<int> less(n);
   less[0] = nums[0];
   vector<int> gre(n);
   gre[n-1] = nums[n-1];
   for(int i=1; i<nums.size(); i++){
       if(nums[i-1] > less[i-1]){
           less[i] = nums[i-1];
       }
       else{
           less[i] = less[i-1];
       }
   }
    for(int i=n-2; i>=0; i--){
       if(nums[i+1] < gre[i+1]){
           gre[i] = nums[i+1];
       }
       else{
           gre[i] = gre[i+1];
       }
   }

   for(auto i:nums) cout<< i << " ";
    cout<< endl;
   for(auto i:less) cout<< i << " " ;
    cout<<endl;
     for(auto i:gre) cout<< i << " " ;
    cout<<endl;

   for(int i=0; i<n; i++){
       if(less[i] < gre[i] and gre[i]<nums[i] and less[i] < nums[i]){
           return true;
       }
   }
   return false;

}

int main(){
    vector<int> nums = {3, 1, 4, 2};
    cout<< find132pattern(nums) << endl;
}