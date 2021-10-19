#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int minSize = 0x3f3f3f3f;
        for (auto str : strs) {
            if (str.length() < minSize) {
                minSize = str.length();
            }
        }
        string sample = strs[0];
        string common = "";
        int len = 0;
        bool flag;
        for (int j = 0; j < minSize; ++j) {
            flag = true;
            for (auto itr = (strs.begin() + 1); itr != strs.end(); ++itr) {
                if ((*itr)[j] != sample[j]) {
                    flag = false;
                    break;
                } else continue;
            }
            if (flag) {
                ++len;
            } else break;
        }
        common = sample.substr(0, len);

        return common;
    }
};
