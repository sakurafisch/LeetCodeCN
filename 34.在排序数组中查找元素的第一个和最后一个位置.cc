#include <algorithm>
#include <vector>
using std::find;
using std::lower_bound;
using std::upper_bound;
using std::vector;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if (find(nums.begin(), nums.end(), target) == nums.end())
            return {-1, -1};
        int low = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int up = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return {low, up};
    }
};
