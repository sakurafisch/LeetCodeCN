#include <vector>
#include <map>
using namespace std;

class Solution
{
  private:
    void dfs(int now, vector<int> &ans, map<int, vector<int>> &child) {
        ans.push_back(now);
        if (child.find(now) != child.end()) {
            for (int next : child[now]) {
                dfs(next, ans, child);
            }
        }
    }

  public:
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill)
    {
        map<int, vector<int>> child;
        for (int i = 0; i < ppid.size(); i++) {
            if (child.find(ppid[i]) == child.end()) {
                child[ppid[i]] = vector<int>();
            }
            child[ppid[i]].push_back(pid.at(i));
        }
        vector<int> ans;
        dfs(kill, ans, child);
        return ans;
    }
};

