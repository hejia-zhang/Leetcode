//
// Created by hjzh on 18-1-9.
//
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())
        {
            return s.empty();
        }

        if (s.empty())
        {
            if (p.size() % 2 == 1)
            {
                return false;
            }

            for (int i = 0; i < p.size(); i++)
            {
                if (i % 2 == 1 && p[i] != '*')
                {
                    return false;
                }
            }

            return true;
        }

        bool res = false;

        if (p.size() >= 2 && p[1] == '*')
        {
            res = (res || isMatch(s, p.substr(2)));
            if (p[0] == s[0] || p[0] == '.')
            {
                res = (res || isMatch(s.substr(1), p));
            }
        }

        if (p[0] == s[0] || p[0] == '.')
        {
            res = (res || isMatch(s.substr(1), p.substr(1)));
        }

        return res;
    }
};

int main()
{
    cout << "Please input your source string: ";
    string t_strSrc;
    cin >> t_strSrc;

    cout << "Please input your pattern string: ";
    string t_strPat;
    cin >> t_strPat;

    Solution sol{};
    if (sol.isMatch(t_strSrc, t_strPat))
    {
        cout << "The pattern matches src str" << endl;
    }
    else {
        cout << "The pattern doesn't match src str" << endl;
    }
}
