class Solution {
public:
    unordered_map<unsigned long long, unsigned long long> m;
    Solution() {
        m[0] = 0;
        m[1] = 1;
        for (int i = 2; i < 115; ++i) {
            m[i] = (m[i - 1] + m[i - 2]) % 1000000007;
        }
    }
    int fib(int n) {
        return m[n];
    }
};
