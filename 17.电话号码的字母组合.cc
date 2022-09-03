#include <vector>
#include <string>
#include <unordered_map>
using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty())
            return ans;
        unordered_map<char, vector<char>> m;
        m['2'] = {'a', 'b', 'c'};
        m['3'] = {'d', 'e', 'f'};
        m['4'] = {'g', 'h', 'i'};
        m['5'] = {'j', 'k', 'l'};
        m['6'] = {'m', 'n', 'o'};
        m['7'] = {'p', 'q', 'r', 's'};
        m['8'] = {'t', 'u', 'v'};
        m['9'] = {'w', 'x', 'y', 'z'};
        ans.push_back("");
        for (int i = 0; i < digits.size(); ++i) {
            vector<char> mv = m[digits[i]];
            vector<string> tmp;
            for (int j = 0; j < mv.size(); ++j)
                for (int k = 0; k < ans.size(); ++k) {
                    tmp.push_back(ans[k] + mv[j]);
                }
            ans = tmp;
        }
        return ans;
    }
};
