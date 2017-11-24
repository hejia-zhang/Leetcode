//
// Created by heikki on 17-11-24.
//
#include <string>
#include <unordered_map>
#include <vector>
#include <cstring>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        size_t t_maxLen = 0;
        string strRes;

        unordered_map<char, vector<size_t>> t_mapCharVecIdx;
        int t_palTable[1000 * 1000];
        memset(t_palTable, 0, sizeof(t_palTable));

        size_t idx = 0;
        for (const auto& val : strRes)
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
                for (const auto& val : iter->second)
                {
                    if (1 == idx - val)
                    {
                        iter->second.push_back(idx);
                        *(t_palTable + val + (idx) * s.length()) = 1;
                    }
                    else if (val < idx - 1)
                    {
                        if ()
                    }
                }
            }
            idx++;
        }
    }
};

int main()
{

}
