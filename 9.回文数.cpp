#include <string>
using std::string;
using std::to_string;

// 节省空间的解法
class Solution1 {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) return false;
        int ret = 0;
        while(x > ret) {
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        return x == ret || x == ret /10;
    }
};

// 双指针,更直观的解法
class Solution2 {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};
