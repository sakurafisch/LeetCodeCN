#include <vector>
#include <algorithm>
using std::vector;
using std::min;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int len = INT_MAX;
        int sum = 0;
        while (right < nums.size()) {
            sum += nums[right];
            ++right;
            if (sum >= target)
                len = min(len, right - left);
            while (sum - nums[left] >= target) {
                sum -= nums[left];
                ++left;
                len = min(len, right - left);
            }
        }
        if (len == INT_MAX)
            return 0;
        return len;
    }
};
