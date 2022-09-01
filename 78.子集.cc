#include <vector>
#include <cmath>
using std::vector;
using std::pow;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        int maxn = pow(2, len);
        vector<vector<int>> ans(maxn);
        for (int i = 0; i < maxn; ++i)
            for (int j = 0; j < len; ++j)
                if ((i >> j) & 1)
                    ans[i].push_back(nums[j]);
        return ans;
    }
};
