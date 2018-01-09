//
// Created by heikki on 17-11-26.
//

#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        // the maximum and minimum number
        const int MIN = - (1 << 31);
        const int MAX = (1 << 31) - 1;

        int res = 0;
        bool b_neg = false;
        int t_ind = 0;
        while (t_ind <= str.size() - 1 && str[t_ind] == ' ')
        {
            t_ind++;
        }

        if (t_ind <= str.size() - 1 && (str[t_ind] == '+' || str[t_ind] == '-'))
        {
            if (str[t_ind] == '-')
            {
                b_neg = true;
            }
            t_ind++;
        }

        while (t_ind <= str.size() - 1 && str[t_ind] == '0')
        {
            t_ind++;
        }

        int digCount = 0;
        while (t_ind <= str.size() - 1 && (str[t_ind] >= '0' && str[t_ind] <= '9'))
        {
            if (digCount == 10)
            {
                if (b_neg)
                {
                    return MIN;
                }
                return MAX;
            }

            int t_dig = str[t_ind] - '0';

            if (digCount == 9)
            {
                if (b_neg)
                {
                    if ((res == - (MIN / 10) && t_dig >= 8) || res > -(MIN / 10))
                    {
                        return MIN;
                    }
                }
                else
                {
                    if ((res == (MAX / 10) && t_dig >= 7) || res > (MAX / 10))
                    {
                        return MAX;
                    }
                }
            }
            res = res * 10 + t_dig;
            digCount++;
            t_ind++;
        }

        if (b_neg)
        {
            res = -res;
        }
        return res;
    }
};

int main()
{
    cout << "Please input your string: ";
    string t_strIn;
    cin >> t_strIn;
    Solution sol{};
    cout << "The int value is: " << sol.myAtoi(t_strIn) << endl;
}