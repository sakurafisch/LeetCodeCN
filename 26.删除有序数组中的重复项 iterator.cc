#include <vector>
using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        auto j = nums.begin() + 1;
        for (auto i = nums.begin() + 1; i != nums.end(); ++i) {
            if (*i != *(i - 1)) {
                *j = *i;
                j = j + 1;
            }
        }
        return j - nums.begin();
    }
};
