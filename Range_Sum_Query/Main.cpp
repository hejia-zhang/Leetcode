//
// Created by heikki on 17-11-29.
//
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums) {
        m_accu.push_back(0);
        for (int val : nums)
        {
            m_accu.push_back(m_accu.back() + val);
        }
    }

    int sumRange(int i, int j) {
        return m_accu[j + 1] - m_accu[i];
    }
    vector<int> m_accu;
};

int main()
{
    string line;
    getline(cin, line);
    istringstream iss(line);
    int t_num;
    vector<int> nums;
    while (iss >> t_num)
    {
        nums.push_back(t_num);
    }
    NumArray obj = NumArray(nums);
    int t_i, t_j;
    while (true)
    {
        cout << "Please input i: ";
        cin >> t_i;
        cout << "Please input j: ";
        cin >> t_j;
        cout << endl;
        cout << "The result is " << obj.sumRange(t_i, t_j) << endl;
    }

}