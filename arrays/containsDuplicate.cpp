// leetcode: https://leetcode.com/problems/contains-duplicate/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            auto it = mp.find(nums[i]);
            if (it != mp.end())
            {
                // number already exist
                return true;
            }
            else
            {
                // insert number into map
                mp[nums[i]] = nums[i];
            }
        }

        return false;
    }
};

int main()
{
    return 0;
}