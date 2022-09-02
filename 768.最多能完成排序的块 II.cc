#include <vector>
#include <algorithm>
using std::vector;
using std::sort;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        long sum1 = 0, sum2 = 0;
        vector<int> t = arr;
        sort(t.begin(), t.end());
        for(int i = 0; i < arr.size(); i++) {
            sum1 += t[i];
            sum2 += arr[i];
            if(sum1 == sum2) ans++;
        }
        return ans;
    }
};
