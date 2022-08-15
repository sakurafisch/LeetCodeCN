function searchInsert(nums: number[], target: number): number {
    let [left, right]  = [0, nums.length - 1];
    while (left <= right) {
        const mid = Math.floor((right - left) / 2 + left);
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
};
