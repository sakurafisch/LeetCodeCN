package Java;

class Solution {
    public String longestCommonPrefix(String[] strs) {
        String ans = strs[0];
        for (int i = 0; i < strs.length; ++i) {
            for (int j = 0; j < ans.length(); ++j) {
                if (j == strs[i].length() || ans.charAt(j) != strs[i].charAt(j)) {
                    ans = ans.substring(0, j);
                    break;
                }
            }
        }
        return ans;
    }
}
