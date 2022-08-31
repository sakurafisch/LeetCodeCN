#include <vector>
#include <queue>
#include <functional>
using std::vector;
using std::priority_queue;
using std::less;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans(k, 0);
        if (k == 0) { // 排除 0 的情况
            return ans;
        }
        priority_queue<int, vector<int>, less<int>> q;
        for (int i = 0; i < k; ++i) {
            q.push(arr[i]);
        }
        for (int i = k; i < arr.size(); ++i) {
            if (q.top() > arr[i]) {
                q.pop();
                q.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i) {
            ans[i] = q.top();
            q.pop();
        }
        return ans;
    }
};
