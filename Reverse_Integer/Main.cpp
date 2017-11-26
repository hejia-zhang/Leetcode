//
// Created by heikki on 17-11-26.
//

#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        const int MIN = - (1 << 31);
        const int MAX = (1 << 31) - 1;
        const unsigned short nMAXDigit = 10;

        bool b_negFlag;
        unsigned int t_absIn;
        unsigned int t_absIn2;
        if (x < 0)
        {
            t_absIn = -x;
            t_absIn2 = -x;
            b_negFlag = true;
        }
        else
        {
            t_absIn = x;
            t_absIn2 = x;
            b_negFlag = false;
        }

        int t_nCountDigit = 0;
        {
            while (t_absIn2 > 0)
            {
                t_nCountDigit += 1;
                t_absIn2 /= 10;
            }
        }

        if (t_nCountDigit > nMAXDigit)
        {
            return 0;
        }

        unsigned int nRes = 0;
        int t_nCountResDigit = 0;
        while (t_absIn > 0)
        {
            nRes = nRes * 10 + t_absIn % 10;
            t_nCountResDigit += 1;
            if (t_nCountDigit == nMAXDigit)
            {
                unsigned int t_nMAX = MAX;
                unsigned int t_nMIN = -MIN;
                for (int i = 1; i <= t_nCountDigit - t_nCountResDigit; i++)
                {
                    t_nMAX /= 10;
                    t_nMIN /= 10;
                }
                if (t_nMAX < nRes || t_nMIN < nRes)
                {
                    return 0;
                }
            }
            t_absIn /= 10;
        }
        if (!b_negFlag)
        {
            return nRes;
        }
        return -nRes;
    }
};

int main()
{
    cout << "Please input your integer: ";
    int t_n;
    cin >> t_n;
    Solution sol{};
    cout << "The reversed int is: " << sol.reverse(t_n) << endl;
}