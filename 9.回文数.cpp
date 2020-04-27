class Solution {
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
