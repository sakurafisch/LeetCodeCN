function twoSum(nums: number[], target: number): number[] {
    const m = new Map<number, number>()
    for (let i = 0; i < nums.length; i++) {
        const another = target - nums[i]
        if (m.has(another)) {
            return [m.get(another), i]
        } else {
            m.set(nums[i], i)
        }
    }
    return []
};
