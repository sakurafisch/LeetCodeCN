#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for (int i = 0; i < strs.size(); ++i) {
            for (int j = 0; j < ans.length(); ++j) {
                if (j == strs[i].length() || strs[i][j] != ans[j]) {
                    ans = ans.substr(0, j);
                    break;
                }
            }
        }
        return ans;
    }
};
