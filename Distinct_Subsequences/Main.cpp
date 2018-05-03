//
// Created by heikki on 18-5-3.
//
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size()) {
            return 0;
        }
        int O[t.size()][s.size()] = {0};
        if (s[0] == t[0]) {
            O[0][0] = 1;
        }
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == t[0]) {
                O[0][i] = O[0][i - 1] + 1;
            } else {
                O[0][i] = O[0][i - 1];
            }
        }
        for (int i = 1; i < t.size(); i++) {
            if (t[i] == s[i]) {
                O[i][i] = O[i - 1][i - 1];
            } else {
                O[i][i] = 0;
            }
            for (int j = i + 1; j < s.size(); j++) {
                if (t[i] == s[j]) {
                    O[i][j] = O[i-1][j-1] + O[i][j-1];
                } else {
                    O[i][j] = O[i][j-1];
                }
            }
        }

        return O[t.size() - 1][s.size() - 1];
    }
};


int main()
{
    string S = "babgbag";
    string T = "bag";
    Solution sol{};
    cout << "The length of distinct subsequences is: " << sol.numDistinct(S, T) << endl;
}