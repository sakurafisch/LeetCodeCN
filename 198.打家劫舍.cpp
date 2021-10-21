#include <vector>
#include <algorithm>
using std::vector;
using std::max;

class Solution {
public:
    int rob(vector<int>& nums) {
        int preMax = 0;
        int curMax = 0;
        for (int x : nums) {
            int tmp = curMax;
            curMax = max(preMax + x, curMax);
            preMax = tmp;
        }
        return curMax;
    }
};
