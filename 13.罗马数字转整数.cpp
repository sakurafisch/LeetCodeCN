class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int sum = 0;
        for (auto itr = s.begin(); itr != s.end() - 1; ++itr) {
            if (m[*itr] < m[*(itr+1)]) {
                sum -= m[*itr];
            } else {
                sum += m[*itr];
            }
        }
        sum += m[*(s.end() - 1)];
        return sum;
    }
};
