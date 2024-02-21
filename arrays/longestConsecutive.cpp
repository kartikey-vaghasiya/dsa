#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]] = nums[i];
    }

    int mx = 0;
    int localMx = 0;

    auto prev = mp.begin();

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it == prev)
        {
            localMx += 1;
        }

        else
        {
            if (it->first == ((prev->first) + 1))
            {
                localMx += 1;
            }

            else
            {
                localMx = 1;
            }
        }

        mx = max(localMx, mx);
        prev = it;
    }

    return mx;
}

int main()
{

    vector<int> nums = {1, 2, 3, 100, 101, 10};
    int ans = longestConsecutive(nums);
    cout << ans;

    return 0;
}