#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;
using std::max;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> chars(128);
        int left = 0, right = 0;
        int ans = 0;
        
        while (right < s.length()) {
            char r = s[right];
            chars[r]++;
            
            while (chars[r] > 1) {
                char l = s[left];
                chars[l]--;
                left++;
            }
            
            ans = max(ans, right - left + 1);
            right++;
        }
        
        return ans;
    }
};
