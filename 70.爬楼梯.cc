#include <unordered_map>
using std::unordered_map;
class Solution {
public:
    unordered_map<int, int> m;
    Solution(){
        m[1] = 1;
        m[2] = 2;
        for (int i = 3; i < 46; ++i) {
            m[i] = m[i - 1] + m[i - 2];
        }
    }
    int climbStairs(int n) {
        return m[n];
    }
};
