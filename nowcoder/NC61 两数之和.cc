#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param numbers int整型vector 
     * @param target int整型 
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        vector<int> ans;
        unordered_map<int, int> m;
        for (int i = 0; i < numbers.size(); ++i) {
            if (m.find(target - numbers[i]) == m.end()) {
                m[numbers[i]] = i;
            } else {
                ans.push_back(m[target - numbers[i]] + 1);
                ans.push_back(i + 1);
                return ans;
            }
        }
        return ans;
    }
};