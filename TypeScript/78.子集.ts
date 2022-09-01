function subsets(nums: number[]): number[][] {
    const len = nums.length
    const maxn = Math.floor(Math.pow(2, len))
    const ans: Array<Array<number>> = [...Array(maxn)].map(_ => Array())
    for (let i = 0; i < maxn; ++i)
        for (let j = 0; j < len; ++j)
            if (((i >> j) & 1) == 1)
                ans[i].push(nums[j])
    return ans
};
