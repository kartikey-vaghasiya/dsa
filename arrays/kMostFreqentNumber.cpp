#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    vector<int> answer;

    // nums vector mathi minimum & maximum findout karvana
    int mx = INT_MIN;
    int mn = INT_MAX;

    for (int i = 0; i < nums.size(); i++)
    {
        mx = max(mx, nums[i]);
        mn = min(mn, nums[i]);
    }

    mx = abs(mx);
    mn = abs(mn);

    // arr of size "mn + mx + 1" rakhi...
    // kem ke jo  nums[i] (-ve) number aavyo to index (-ve) ma assign nai kari saki
    // etla mate "arr[ nums[i] ]" ma index na badle jo "arr[ nums[i] + mn ]" index api to
    // jo mininum number pan "+ mn" sathe cancel out thai ne "0" apse (aavi rite index prob solved )
    // answer ma push karti vakhte "index - mn" kari devanu etle orignal number avi jase
    int *arr = new int[mx + mn + 1]();

    for (int i = 0; i < nums.size(); i++)
    {
        arr[nums[i] + mn] += 1;
    }

    // now finding k most frequent repeated number
    for (int i = 0; i < k; i++)
    {
        int maxFreq = INT_MIN;
        int maxFreqIndex = 0;
        for (int j = 0; j < mn + mx + 1; j++)
        {
            if (arr[j] > maxFreq)
            {
                maxFreqIndex = j;
                maxFreq = arr[j];
            }
        }
        answer.push_back(maxFreqIndex - mn); // -mn kairu kem ke arr ma "orignalIndex+mn" ma index ee value store karta ta
        arr[maxFreqIndex] = 0;
    }

    delete[] arr;
    return answer;
}

int main()
{

    vector<int> nums = {-1, -1};
    vector<int> answer = topKFrequent(nums, 1);

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    return 0;
}