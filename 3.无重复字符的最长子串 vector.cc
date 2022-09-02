#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;
using std::max;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        if (s.empty())
            return ans;
        vector<bool> vec(128);
        int left = 0, right = 0;
        while (right < s.length()) {
            if (vec[s[right]] == false) {
                vec[s[right]] = true;
                ans = max(ans, right - left + 1);
                ++right;
            } else {
                vec[s[left]] = false;
                ++left;
            }
        }
        return ans;
    }
};
