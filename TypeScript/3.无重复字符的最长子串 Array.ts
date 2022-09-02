function lengthOfLongestSubstring(s: string): number {
    let ans: number = 0
    if (s.length === 0)
        return ans
    const arr = new Array<boolean>(128).fill(false)
    let [left, right] = [0, 0]
    while (right < s.length) {
        if (arr[s.charCodeAt(right)] == false) {
            arr[s.charCodeAt(right)] = true
            ans = Math.max(ans, right - left + 1)
            ++right
        } else {
            arr[s.charCodeAt(left)] = false
            ++left
        }
    }
    return ans
};
