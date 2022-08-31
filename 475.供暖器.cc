#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int ans = 0;
        sort(heaters.begin(), heaters.end());
        for (int x : houses) {
            int right = upper_bound(heaters.begin(), heaters.end(), x) - heaters.begin();
            int left = right - 1;
            int right_distance = right > heaters.size() - 1 ? INT_MAX : heaters[right] - x;
            int left_distance = left < 0 ? INT_MAX : x - heaters[left];
            int cur_distance = min(left_distance, right_distance);
            ans = max(ans, cur_distance);
        }
        return ans;
    }
};
