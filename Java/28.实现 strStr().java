class Solution {
    public int strStr(String haystack, String needle) {
        for (int i = 0; i + needle.length() <= haystack.length(); ++i) {
            Boolean match = true;
            for (int j = 0; j < needle.length(); ++j) {
                if (i + j == haystack.length()) {
                    return -1;
                }
                if (haystack.charAt(i+j) != needle.charAt(j)) {
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
}