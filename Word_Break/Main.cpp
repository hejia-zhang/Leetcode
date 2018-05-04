//
// Created by hejia on 5/3/18.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // maintains the index that s.substring(0, index) that can be represented with wordDict
        int true_indexes[s.size() + 1]{0};
        // maintains the number of true indexes
        int n_count_true = 1;
        true_indexes[n_count_true - 1] = -1;
        // maintains the longest word length
        int max_length = 0;

        for (auto& val: wordDict) {
            if (val.size() > max_length) {
                max_length = val.size();
            }
        }

        for (int i = 0; i < s.size(); i++) {
            int min_sub_string_length = i - true_indexes[n_count_true - 1];
            if (min_sub_string_length > max_length) {
                return false;
            }
            bool find = false;
            for (int j = n_count_true; j > 0; j--) {
                int sub_string_length = i - true_indexes[j - 1];
                if (sub_string_length > max_length) {
                    break;
                }
                string substring = s.substr(true_indexes[j - 1] + 1, sub_string_length);
                for (auto& val: wordDict) {
                    if (val == substring) {
                        n_count_true += 1;
                        true_indexes[n_count_true - 1] = i;
                        find = true;
                        break;
                    }
                }
                if (find) {
                    break;
                }
            }
        }

        if (true_indexes[n_count_true - 1] == s.size() - 1) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {

    string s = "leetcode";
    vector<string> wordDict{"leet", "code"};
    Solution sol{};
    if (!sol.wordBreak(s, wordDict)) {
        cout << "False" << endl;
    } else {
        cout << "True" << endl;
    }
}

