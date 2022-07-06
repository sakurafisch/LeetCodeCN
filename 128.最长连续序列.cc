#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int ans = 1;
        sort(nums.begin(), nums.end());
        vector<int> uni;
        uni.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != uni.back()) {
                uni.push_back(nums[i]);
            }
        }
        int left = 0, right = 0;
        while (right < uni.size() - 1) {
            if (uni[right] + 1 == uni[right + 1]) {
                ++right;
                ans = max(ans, right - left + 1);
            } else {
                right = right + 1;
                left = right;
            }
        }
        return ans;
    }
};
