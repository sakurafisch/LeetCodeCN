#include <algorithm>
#include <vector>
#include <set>
using std::vector;
using std::set;
using std::sort;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};
        vector<vector<int>> ans;
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            int target = -nums[i];
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] == target) {
                    if (st.find({-target, nums[left], nums[right]}) == st.end()) {
                        st.insert({-target, nums[left], nums[right]});
                        ans.push_back({-target, nums[left], nums[right]});
                    }
                    ++left;
                    --right;
                }
                else if (nums[left] + nums[right] < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return ans;
    }
};
    