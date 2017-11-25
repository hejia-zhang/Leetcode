//
// Created by heikki on 17-11-24.
//
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        string strRes;

        if (1 == numRows)
        {
            return s;
        }

        if (numRows > s.length())
        {
            numRows = s.length();
        }

        for (int i = 1; i <= numRows; i++)
        {
            bool t_bNew;
            size_t t_now = i - 1;
            size_t t_next1;
            size_t t_next2;
            strRes += s[t_now];
            do
            {
                t_bNew = false;
                t_next1 = t_now + ((numRows - i) << 1);
                t_next2 = t_next1 + ((i - 1) << 1);
                if (t_next1 != t_now && t_next1 <= s.length() - 1)
                {
                    strRes += s[t_next1];
                    t_bNew = true;
                }
                if (t_next2 != t_next1 && t_next2 <= s.length() - 1)
                {
                    strRes += s[t_next2];
                    t_bNew = true;
                }
                if (t_bNew)
                {
                    t_now = t_next2;
                }
            }
            while (t_bNew);
        }
        return strRes;
    }
};

int main()
{
    cout << "Please input your string: ";
    string t_strIn;
    cin >> t_strIn;
    cout << "Please input the number of rows: ";
    int t_nRows;
    cin >> t_nRows;
    Solution sol{};
    cout << "The converted string is: " << sol.convert(t_strIn, t_nRows) << endl;
}
