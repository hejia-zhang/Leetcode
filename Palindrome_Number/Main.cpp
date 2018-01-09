//
// Created by hjzh on 18-1-9.
//
#include <iostream>

using namespace std;

class Solution
{
public:
    int calDigCount(int x)
    {
        int t_in = x;
        int res = 0;

        while (t_in > 0)
        {
            res++;
            t_in /= 10;
        }
        return res;
    }

    bool isPalindrome(int x)
    {
        int digCot = calDigCount(x);
        int lDigCot = digCot / 2;
        int mid = digCot % 2;
        int rDigCot = lDigCot;

        int left = 0;
        int rightCopy = x;

        for (int i = 0; i < lDigCot; i++)
        {
            int t_dig = rightCopy % 10;
            left = left * 10 + t_dig;
            rightCopy /= 10;
        }

        for (int i = 0; i < mid; i++)
        {
            rightCopy /= 10;
        }

        if (rightCopy == left)
        {
            return true;
        }

        return false;
    }
};

int main()
{
    cout << "Please input your integer: ";
    int t_n;
    cin >> t_n;
    Solution sol{};
    if (sol.isPalindrome(t_n))
    {
        cout << "The input integer is palindrome" << endl;
    }
    else
    {
        cout << "The input integer is not palindrome" << endl;
    }
}
