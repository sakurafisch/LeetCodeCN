#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int cur = 0;
        int max_far = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            max_far = max(max_far, i + nums[i]);
            if (i == cur) {
                cur = max_far;
                ++ans;
            }
        }
        return ans;
    }
};
