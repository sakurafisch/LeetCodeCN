#include <string>
using std::string;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i + needle.size() <= haystack.size(); ++i) {
            bool match = true;
            for (int j = 0; j < needle.size(); ++j) {
                if (i + j == haystack.size()) {
                    return -1;
                }
                if (haystack[i + j] != needle[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return i;
            }
        }
        return -1;
    }
};