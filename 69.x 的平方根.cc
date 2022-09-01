class Solution {
public:
    int mySqrt(int x) {
        if (1 == x) {
            return 1;
        }
        int min = 0;
        int max = x;
        int m;
        while (max - min > 1) {
            m = (max + min) / 2;
            if (x / m < m) {
                max = m;
            } else {
                min = m;
            }
        }
        return min;
    }
};
