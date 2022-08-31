#include <vector>
#include <algorithm>
#include <ctime>

using std::vector;
using std::swap;

class Solution {
private:
    int partition(vector<int> & nums, int left, int right) {
        int pivot = nums[right];
        int i = left;
        for (int j = left; j < right; ++j) {
            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                ++i;
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }

    int randomized_partition(vector<int> & nums, int left, int right) {
        int x = left + rand() % (right - left + 1);
        swap(nums[x], nums[right]);
        return partition(nums, left, right);
    }

    void quickSort(vector<int> & nums, int left, int right) {
        if (left < right) {
            int pos = randomized_partition(nums, left, right);
            quickSort(nums, left, pos - 1);
            quickSort(nums, pos + 1, right);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(nullptr));
        quickSort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
};
