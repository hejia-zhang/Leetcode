//
// Created by heikki on 17-11-30.
//

#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;
class Solution {
public:
    int rob(vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        if (nums.size() == 1)
        {
            return nums[0];
        }
        if (nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }
        if (nums.size() == 3)
        {
            return max(max(nums[0], nums[1]), nums[2]);
        }

        int resNotConn[nums.size() - 1];
        memset(resNotConn, 0, sizeof(resNotConn));
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (i < 2)
            {
                resNotConn[i] = max(nums[i], nums[0]);
            }
            else
            {
                resNotConn[i] = max(resNotConn[i - 1], resNotConn[i - 2] + nums[i]);
            }
        }

        int resNotConn2[nums.size() - 3];
        memset(resNotConn2, 0, sizeof(resNotConn2));
        for (int i = 1; i < nums.size() - 2; i++)
        {
            if (i < 3)
            {
                resNotConn2[i - 1] = max(nums[i], nums[1]);
            }
            else
            {
                resNotConn2[i - 1] = max(resNotConn2[i - 2], resNotConn2[i - 3] + nums[i]);
            }
        }
        return max(resNotConn[nums.size() - 2], resNotConn2[nums.size() - 4] + nums[nums.size() - 1]);
    }
};

int main()
{
    string line;
    getline(cin, line);
    int t_num;
    std::vector<int> nums;
    istringstream iss{line};
    while (iss >> t_num)
    {
        nums.push_back(t_num);
    }
    Solution sol;
    cout << sol.rob(nums) << endl;
}