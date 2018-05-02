//
// Created by heikki on 18-5-2.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int sum[triangle.size()];
        for (auto& val : sum) {
            val = 0;
        }
        sum[0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = i; j >= 0; j--) {
                if (j == i) {
                    sum[j] = triangle[i][j] + sum[j-1];
                } else if (j == 0) {
                    sum[j] = triangle[i][j] + sum[j];
                } else {
                    sum[j] = min(sum[j-1] + triangle[i][j], triangle[i][j] + sum[j]);
                }
            }
        }

        int result = INT32_MAX;
        for (auto& val : sum) {
            if (val < result) {
                result = val;
            }
        }

        return result;
    }

    int min(int a, int b) {
        return a > b? b: a;
    }
};

int main()
{
    vector<vector<int>> triangle{vector<int>{2}, vector<int>{3, 4}, vector<int>{5, 6, 7}, vector<int>{4, 1, 8, 3}};
    Solution sol{};
    cout << "The minimum sum value is: " << sol.minimumTotal(triangle) << endl;
}