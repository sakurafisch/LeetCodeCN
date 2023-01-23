function maxSubArray(nums: number[]): number {
    const dp = new Array(nums.length);
    dp[0] = nums[0];
    for (let i = 1; i < nums.length; ++i)
        dp[i] = dp[i-1] > 0 ? dp[i-1] + nums[i] : nums[i];
    return Math.max(...dp);
};
