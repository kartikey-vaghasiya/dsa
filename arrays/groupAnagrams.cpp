#include <bits/stdc++.h>
using namespace std;

void printVector(vector<string> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == "")
        {
            cout << "e";
        }

        else
        {
            cout << v[i] << " ";
        }
    }

    cout << endl;
}

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> answer;
    unordered_map<string, vector<string>> mp;

    // "multimap" is used for storing multikey value,
    // string ne sort karva "multimap" use karyo chhe,
    // for example: jo string "babac" chhe to "unorderd_map / map" thi multi-key map na banavi saki,
    // pan multimap numbers ne sorted order ma store karse
    // for example: babac ne aabbc store karse
    multimap<char, char> m;

    for (int i = 0; i < strs.size(); i++)
    {
        m.clear();

        // sorting the string ( strs[i] )
        for (int j = 0; j < strs[i].size(); j++)
        {
            m.insert(make_pair(strs[i][j], strs[i][j]));
        }

        string sortedString;

        // converting multimap to string
        int k = 0;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            sortedString.push_back(it->first);
        }

        vector<string> v;
        auto it = mp.find(sortedString);
        // insert sortedString into unordered_map  as a key if it's not in unordered_map
        if (it == mp.end())
        {
            v.push_back(strs[i]);
            mp.insert(make_pair(sortedString, v));
        }
        // if sortedString already present in unordered_map then insert sortedString on vector
        else
        {
            vector<string> &v = mp[sortedString];
            v.push_back(strs[i]);
        }
    }

    // converting unordered_map to vector
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        answer.push_back(it->second);
    }

    return answer;
}

int main()
{
    return 0;
}
