#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true;
        stack<char> sta;
        for(auto itr = s.begin(); itr != s.end(); ++itr) {
            if (*itr == '(' || *itr == '{' || *itr == '[') {
                sta.push(*itr);
                continue;
            }
            else if (*itr == ')') {
                if (sta.empty() || sta.top() != '(') {
                    return false;
                } else {
                    sta.pop();
                }
            }
            else if (*itr == '}') {
                if (sta.empty() || sta.top() != '{') {
                    return false;
                } else {
                    sta.pop();
                }
            }
            else if (*itr == ']') {
                if (sta.empty() || sta.top() != '[') {
                    return false;
                } else {
                    sta.pop();
                }
            }
        }
        if (sta.empty()) return true; 
        else return false;
    }
};
