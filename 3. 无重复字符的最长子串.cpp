#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int left = 0, right = 0;
        set<char> st;
        while (right < s.length()) {
            if (st.find(s[right]) == st.end()) {
                st.insert(s[right]);
                ans = max(ans, right - left + 1);
                ++right;
            } else {
                st.erase(st.find(s[left]));
                ++left;
            }
        }
        return ans;
    }
};