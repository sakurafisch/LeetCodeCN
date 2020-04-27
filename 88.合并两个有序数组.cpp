class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (!m) {
            nums1 = nums2;
            return;
        }
        if (!n) return;
        auto itr1 = nums1.begin() + m;
        auto itr2 = nums2.begin();
        while (itr1 != nums1.end() && itr2 != nums2.end()) {
            *itr1 = *itr2;
            ++itr2;
            ++itr1;
        }
        sort(nums1.begin(), nums1.end());
        return;
    }
};
