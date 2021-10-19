/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

#include <vector>
#include <algorithm>
using std::vector;
using std::swap;

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty()) return;
        auto itr = s.begin();
        auto ritr = s.end() - 1;
        while(itr < ritr) {
            swap(*itr, *ritr);
            ++itr;
            --ritr;
        }
        return;
    }
};
// @lc code=end

