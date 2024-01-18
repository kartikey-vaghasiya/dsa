// leetcode: https://leetcode.com/problems/contains-duplicate/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool containsDuplicate(vector<int>& nums){
        map<int,int> mp;

        for(int i = 0; i < nums.size(); i++){
            auto it = mp.find(nums[i]);
            if ( it != mp.end()){
                // key exist
                return true;
            } else {
                mp[nums[i]] = nums[i];
            }
        }

        return false;
    }
};

int main(){
   
    return 0;
}