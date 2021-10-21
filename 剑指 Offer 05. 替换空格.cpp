#include <string>
using std::string;

class Solution {
public:
    string replaceSpace(string s) {
        string ans = "";
        for (int i = 0; i < s.length(); ++i) {
            if (isspace(s[i])) {
                ans += "%20";
                continue;
            }
            ans += s[i];
        }
        return ans;
    }
};
