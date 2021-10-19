/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        string pre = "";
        string ans = "";
        for(int i = 0; i < s.length(); ++i) {
            if(s.at(i) != ' ') {
                ans += s.at(i);
            } else {
                if (ans != "") {
                    pre = ans;
                    ans = "";
                } else {
                    continue;
                }
            }
        }
        return ans == "" ? pre.length() : ans.length();
    }
};
// @lc code=end

