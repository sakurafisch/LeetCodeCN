function lengthOfLongestSubstring(s: string): number {
    let ans = 0
    const st = new Set<string>()
    let left = 0, right = 0
    while (right < s.length) {
        if (!st.has(s[right])) {
            st.add(s[right])
            ans = Math.max(ans, right - left + 1)
            right++
        } else {
            st.delete(s[left])
            left++
        }
    }
    return ans
};
