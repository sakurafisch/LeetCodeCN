#include <vector>
using std::vector;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int x : nums) {
            int num = abs(x);
            if (nums[num - 1] < 0) {
                ans.push_back(num);
            } else {
                nums[num - 1] = -nums[num - 1];
            }
        }
        return ans;
    }
};
