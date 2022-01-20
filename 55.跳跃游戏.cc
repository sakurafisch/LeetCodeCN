#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_num = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i <= max_num) {
                max_num = max(max_num, i + nums[i]);
                if (max_num >= nums.size() - 1)
                    return true;
            }
        }
        return false;
    }
};
