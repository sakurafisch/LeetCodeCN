#include <vector>
#include <algorithm>

using std::vector;
using std::max;
using std::min;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi = 0x3f3f3f3f;
        int ans = 0;
        for (int x : prices) {
            ans = max(ans, x - mi);
            mi = min(mi, x);
        }
        return ans;
    }
};
