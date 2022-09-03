function longestPalindrome(s: string): string {
    if (s.length == 0) {
        return "";
    }
    let ans: string = s.substring(0, 1);
    // let ans: string = s.slice(0, 1);
    // let ans: string = s.substr(0, 1);
    for (let i = 0; i < s.length - 1; ++i) {
        let tmp: string = midToSize(s, i, i);
        if (tmp.length > ans.length) {
            ans = tmp;
        }
        tmp = midToSize(s, i, i + 1);
        if (tmp.length > ans.length) {
            ans = tmp;
        }
    }
    return ans;
};

function midToSize(s: string, left: number, right: number): string {
    while (left >= 0 && right < s.length && s[left] == s[right]) {
        --left; ++right;
    }
    return s.substring(left + 1, right);
    // return s.slice(left+1, right);
    // return s.substr(left+1, right-left-1);
}
