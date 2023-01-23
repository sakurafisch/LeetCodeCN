class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int last = 0, ans = nums[0];
        for (const int& x : nums) {
            last = max(last + x, x);
            ans = max(ans, last);
        }
        return ans;
    }
};