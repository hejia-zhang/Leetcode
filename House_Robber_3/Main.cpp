//
// Created by heikki on 17-12-3.
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <random>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *makeTree(vector<int>& nums)
{
    if (nums.size() == 0)
    {
        return nullptr;
    }

    default_random_engine t_ranEng;
    uniform_int_distribution<> u(0, 1);

    for (const auto& val : nums)
    {

    }
}

class Solution {
public:
    int rob(TreeNode* root) {

    }
};

int main()
{
    string line;
    getline(cin, line);
    istringstream iss{line};
    int t_num;
    vector<int> t_nums;
    while (iss >> t_num)
    {
        t_nums.push_back(t_num);
    }

    TreeNode *root = makeTree(t_nums);

    Solution sol = Solution{};
    cout << "The maximum amount of money the thief can rob is " << sol.rob(root) << endl;
}
