function convert(s: string, numRows: number): string {
    const t = new Array<string>(numRows).fill("")
    let ans: string = ""
    let i: number = 0
    while (i < s.length) {
        for (let j = 0; j < numRows && i < s.length; ++j) {
            t[j] += s[i++]
        }
        for (let k = numRows - 2; k > 0 && i < s.length; --k) {
            t[k] += s[i++]
        }
    }
    for (const x of t) {
        ans += x
    }
    return ans
};

