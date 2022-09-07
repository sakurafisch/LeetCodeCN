#include <vector>
using std::vector;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int right1 = m - 1, right2 = n - 1;
        int right3 = m + n - 1;
        while (right1 >= 0 || right2 >= 0) {
            if (right1 == -1)
                nums1[right3--] = nums2[right2--];
            else if (right2 == -1)
                nums1[right3--] = nums1[right1--];
            else if (nums1[right1] > nums2[right2]) {
                nums1[right3--] = nums1[right1--];
            }
            else {
                nums1[right3--] = nums2[right2--];
            }
        }
    }
};
