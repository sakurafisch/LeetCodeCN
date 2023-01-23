function maxSubArray(nums: number[]): number {
    let [last, ans] = [0, nums[0]];
    for (const x of nums) {
        last = Math.max(last + x, x);
        ans = Math.max(ans, last);
    }
    return ans;
};
