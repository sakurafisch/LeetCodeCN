// 定义一个函数f(n)，以第n个数为结束点的子数列的最大和，存在递推关系 f(n) = max(f(n-1) + A[n], A[n]);
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ans = INT_MIN;
        int f_n = -1;
        for (int i = 0; i < nums.size(); ++i) {
            f_n = max(nums[i] , f_n + nums[i]);
            ans = max(f_n, ans); 
        }
        return ans;
    }
};
