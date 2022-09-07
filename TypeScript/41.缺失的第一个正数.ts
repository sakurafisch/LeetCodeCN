function firstMissingPositive(nums: number[]): number {
    const n = nums.length
    nums = nums.map(x => x <= 0 ? n + 1 : x)
    for (let i = 0; i < n; ++i) {
        const x = Math.abs(nums[i])
        if (x <= n)
            nums[x-1] = -Math.abs(nums[x-1])
    }
    for (let i = 0; i < n; ++i) {
        if (nums[i] > 0)
            return i + 1
    }
    return n + 1
};
