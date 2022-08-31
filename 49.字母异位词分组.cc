#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string& x : strs) {
            string key = x;
            sort(key.begin(), key.end());
            mp[key].emplace_back(x);
        }
        vector<vector<string>> ans;
        for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
            ans.emplace_back(itr->second);
        }
        return ans;
    }
};
