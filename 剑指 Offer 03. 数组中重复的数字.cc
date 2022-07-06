#include <vector>
#include <set>
using std::vector;
using std::set;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        set<int> s;
        for (int x : nums) {
            if (s.find(x) != s.end())
                return x;
            s.insert(x);
        }
        return -1;
    }
};
