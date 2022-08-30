#include <string>
using std::string;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i + needle.size() <= haystack.size(); ++i ) {
            bool match = true;
            for (int j = 0; j < needle.size(); ++j) {
                if (haystack[i + j] != needle[j]) {
                    match = false;
                    break;
                }
            }
            if (match == true) {
                return i;
            }
        }
        return -1;
    }
};
