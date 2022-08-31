#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int min_num = *min_element(nums.begin(), nums.end());
        for (int x : nums) {
            ans += x - min_num;
        }
        return ans;
    }
};
