#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        intervals.push_back(newInterval);
        if (intervals.empty())
            return ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i)
            if (ans.back()[1] < intervals[i][0])
                ans.push_back(intervals[i]);
            else
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        return ans;
    }
};

