#include <vector>
#include <unordered_map>
#include <algorithm>

using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty()) return nums1;
        if (nums2.empty()) return nums2;
        // sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        // auto last1 = unique(nums1.begin(), nums1.end());
        auto last2 = unique(nums2.begin(), nums2.end());
        // nums1.erase(last1, nums1.end());
        nums2.erase(last2, nums2.end());
        unordered_map<int, int> m;
        vector<int> ans;
        for (int i = 0; i < nums1.size(); ++i) {
            m[nums1[i]] = i;
        }
        for (int i = 0; i < nums2.size(); ++i) {
            if (m.find(nums2[i]) != m.end()) ans.push_back(nums2[i]);
        }
        return ans;
    }
};
