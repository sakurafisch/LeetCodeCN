#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> t(numRows);
        string ans;
        int i = 0;
        while (i < s.length()) {
            for (int j = 0; j < numRows && i < s.length(); ++j) {
                t[j] += s[i++];
            }
            for (int k = numRows - 2; k > 0 && i < s.length(); --k) {
                t[k] += s[i++];
            }
        }
        for (string x : t) {
            ans += x;
        }
        return ans;
    }
};
