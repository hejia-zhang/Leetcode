//
// Created by heikki on 17-11-24.
//
#include <string>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        size_t t_maxLen = 0;
        string strRes;

        unordered_map<char, vector<size_t>> t_mapCharVecIdx;
        unsigned short t_palTable[1000 * 1000];
        memset(t_palTable, 0, sizeof(t_palTable));

        size_t idx = 0;
        for (const auto& val : s)
        {
            const auto& iter = t_mapCharVecIdx.find(val);
            // If the char shows up first time
            if (iter == t_mapCharVecIdx.end())
            {
                if (t_maxLen < 1)
                {
                    t_maxLen = 1;
                    strRes = val;
                }
                t_mapCharVecIdx.insert(pair<char, vector<size_t >>{val, vector<size_t >{idx}});
            }
            else
            {
                iter->second.push_back(idx);
                for (const auto& val : iter->second)
                {
                    if ((idx - val <= 2) || (*(t_palTable + val + 1 + (idx - 1) * s.length()) == 1))
                    {
                        *(t_palTable + val + (idx) * s.length()) = 1;
                        if (t_maxLen < idx - val + 1)
                        {
                            t_maxLen = idx - val + 1;
                            strRes = s.substr(val, idx - val + 1);
                        }
                    }
                }
            }
            idx++;
        }
        return strRes;
    }
};

int main()
{
    cout << "Please input your string: ";
    string t_strIn;
    cin >> t_strIn;
    Solution sol{};
    cout << "The longest palindromic substring is: " << sol.longestPalindrome(t_strIn) << endl;
}
