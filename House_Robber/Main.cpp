//
// Created by heikki on 17-11-29.
//
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }

        int res[nums.size()];
        res[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (i < 2)
            {
                res[i] = max(nums[i], res[0]);
            }
            else
            {
                res[i] = max(res[i - 1], res[i - 2] + nums[i]);
            }
        }
        return res[nums.size() - 1];
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