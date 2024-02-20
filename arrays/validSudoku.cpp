#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    // row wise check
    for (int i = 0; i < 9; i++)
    {
        unordered_map<char, char> mp;
        for (int j = 0; j < 9; j++)
        {
            auto it = mp.find(board[i][j]);
            if (it != mp.end() && it->first != '.')
            {
                return false;
            }
            else
            {
                mp[board[i][j]] = board[i][j];
            }
        }
    }
    // col wise check
    for (int i = 0; i < 9; i++)
    {
        unordered_map<char, char> mp;
        for (int j = 0; j < 9; j++)
        {
            auto it = mp.find(board[j][i]);
            if (it != mp.end() && it->first != '.')
            {
                return false;
            }
            else
            {
                mp[board[j][i]] = board[j][i];
            }
        }
    }

    // 3X3 box wise
    for (int startRow = 0; startRow < 9; startRow += 3)
    {
        for (int startCol = 0; startCol < 9; startCol += 3)
        {
            unordered_map<char, char> mp;
            for (int i = startRow; i < startRow + 3; i++)
            {
                for (int j = startCol; j < startCol + 3; j++)
                {
                    auto it = mp.find(board[i][j]);
                    if (it != mp.end() && it->first != '.')
                    {
                        return false;
                    }

                    else
                    {
                        mp[board[i][j]] = board[i][j];
                    }
                }
            }
        }
    }

    return true;
}

int main()
{
    return 0;
}