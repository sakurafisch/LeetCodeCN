#include <vector>
#include <algorithm>
using std::vector;
using std::sort;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 2; --i) {
            int left = 0, right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    ans += right - left;
                    --right;
                } else {
                    ++left;
                }
            }
        }
        return ans;
    }
};
