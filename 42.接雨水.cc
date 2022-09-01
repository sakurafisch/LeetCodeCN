#include <vector>
#include <cmath>
using std::vector;
using std::max;
using std::min;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        if (height.empty())
            return ans;
        vector<int> leftheight(n);
        vector<int> rightheight(n);
        leftheight[0] = height[0];
        rightheight[n-1] = height[n-1];
        for (int i = 1; i < n; ++i)
            leftheight[i] = max(leftheight[i-1], height[i]);
        for (int i = n - 2; i >= 0; --i)
            rightheight[i] = max(rightheight[i+1], height[i]);
        for (int i = 0; i < n; ++i)
            ans += min(leftheight[i], rightheight[i]) - height[i];
        return ans;
    }
};
