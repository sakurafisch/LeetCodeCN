#include <vector>
#include <algorithm>
using std::vector;
using std::copy;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty())
            return 0;
        vector<int> ans;
        ans.push_back(nums[0]);
        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1])
                ++count;
            else
                count = 1;
            if (count <= 2)
                ans.push_back(nums[i]);
        }
        copy(ans.begin(), ans.end(), nums.begin());
        return ans.size();
    }
};
