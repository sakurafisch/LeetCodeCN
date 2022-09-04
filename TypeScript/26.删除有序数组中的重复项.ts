function removeDuplicates(nums: number[]): number {
    if (nums.length == 0) {
        return 0;
    }
    let j: number = 1;
    for (let i = 1; i < nums.length; ++i)
        if (nums[i] != nums[i - 1])
            nums[j++] = nums[i];
    return j;
};
