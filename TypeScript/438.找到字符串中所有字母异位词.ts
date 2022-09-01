function findAnagrams(s: string, p: string): number[] {
    const ans: Array<number> = new Array<number>()
    if (s.length < p.length) {
        return ans
    }
    const sts: Array<number> = new Array<number>(26).fill(0)
    const stp: Array<number> = new Array<number>(26).fill(0)
    for (let i = 0; i < p.length; ++i) {
        ++sts[s.charCodeAt(i) - 'a'.charCodeAt(0)]
        ++stp[p.charCodeAt(i) - 'a'.charCodeAt(0)]
    }
    if (JSON.stringify(sts) === JSON.stringify(stp)) {
        ans.push(0)
    }
    let left: number = 0;
    while (left + p.length < s.length) {
        --sts[s.charCodeAt(left) - 'a'.charCodeAt(0)]
        ++sts[s.charCodeAt(left + p.length) - 'a'.charCodeAt(0)]
        ++left
        if (JSON.stringify(sts) === JSON.stringify(stp)) {
            ans.push(left)
        }
    }
    return ans
};
