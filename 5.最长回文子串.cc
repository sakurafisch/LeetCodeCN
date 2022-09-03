#include <string>
using std::string;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";
        string ans = s.substr(0, 1);
        for (int i = 0; i < s.length(); ++i) {
            string tmp = midToSize(s, i, i);
            if (tmp.length() > ans.length()) {
                ans = tmp;
            }
            tmp = midToSize(s, i, i + 1);
            if (tmp.length() > ans.length()) {
                ans = tmp;
            }
        }
        return ans;
    }

    string midToSize(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return s.substr(left + 1, right - left - 1);
    }
};
