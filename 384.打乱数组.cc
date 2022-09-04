#include <algorithm>
#include <vector>
using std::copy;
using std::swap;
using std::vector;

class Solution {
private:
    vector<int> shuffled;
    vector<int> original;

public:
    Solution(vector<int> &nums) {
        this->shuffled = nums;
        this->original.resize(shuffled.size());
        copy(shuffled.begin(), shuffled.end(), original.begin());
    }

    vector<int> reset() {
        copy(original.begin(), original.end(), shuffled.begin());
        return shuffled;
    }

    vector<int> shuffle() {
        for (int i = 0; i < shuffled.size(); ++i)
        {
            int j = i + rand() % (shuffled.size() - i);
            swap(shuffled[i], shuffled[j]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */