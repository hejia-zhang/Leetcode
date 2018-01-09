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

class Solution {
public:
    int rob(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int grandll = 0;
        int grandlr = 0;
        int grandrl = 0;
        int grandrr = 0;

        if (root->left != nullptr)
        {
            grandll = rob(root->left->left);
            grandlr = rob(root->left->right);

        }

        if (root->right != nullptr)
        {
            grandrl = rob(root->right->left);
            grandrr = rob(root->right->right);
        }

        return max(rob(root->left) + rob(root->right), root->val + grandll + grandlr + grandrl + grandrr);
    }
};

int main()
{
    TreeNode root(3);
    TreeNode l(2);
    TreeNode r(3);
    TreeNode lr(3);
    TreeNode rr(1);

    root.left = &l;
    root.right = &r;
    l.right = &lr;
    r.right = &rr;

    Solution sol = Solution{};
    cout << "The maximum amount of money the thief can rob is " << sol.rob(&root) << endl;
}
