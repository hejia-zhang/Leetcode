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