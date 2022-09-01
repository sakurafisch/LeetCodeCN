#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.size() < p.size())
            return ans;
        vector<int> stp(26);
        vector<int> sts(26);
        for (int i = 0; i < p.size(); ++i) {
            ++stp[p[i] - 'a'];
            ++sts[s[i] - 'a'];
        }
        if (stp == sts) {
            ans.push_back(0);
        }
        int left = 0;
        while (left + p.size() < s.size()) {
            --sts[s[left] - 'a'];
            ++sts[s[left + p.size()] - 'a'];
            ++left;
            if (sts == stp) {
                ans.push_back(left);
            }
        }
        return ans;
    }
};
