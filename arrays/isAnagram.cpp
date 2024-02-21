#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {

        if (s.length() != t.length())
        {
            return false;
        }

        int arr[123] = {0}; // ascii of a-z : 97-122

        for (int i = 0; i < s.length(); i++)
        {
            int asciiValue = int(s[i]);
            arr[asciiValue] += 1;
        }

        for (int i = 0; i < t.length(); i++)
        {
            int asciiValue = int(t[i]);
            arr[asciiValue] -= 1;
        }

        // if all elements between index 97-122 are not 0 --> return false;
        for (int i = 97; i < 123; i++)
        {
            if (arr[i] != 0)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    return 0;
}

/*

METHOD-2

bool isAnagram(string s, string t){

    if (s.length() != t.length())
    {
        return false;
    }

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != t[i])
        {
            return false;
        }
    }

    return true;
}
*/