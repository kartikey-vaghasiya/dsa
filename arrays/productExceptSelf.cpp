#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> ans;

    int *left = new int[sizeof(int) * nums.size()];
    left[0] = 1;
    int *right = new int[sizeof(int) * nums.size()];
    right[nums.size() - 1] = 0;

    // left
    for (int i = 1; i < nums.size(); i++)
    {
        left[i] = nums[i - 1] * left[i - 1];
    }

    // right
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        right[i] = nums[i + 1] * right[i + 1];
    }

    // left * right
    for (int i = 0; i < nums.size(); i++)
    {
        ans.push_back(left[i] * right[i]);
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = productExceptSelf(nums);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
