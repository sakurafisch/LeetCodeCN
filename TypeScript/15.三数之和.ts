function threeSum(nums: number[]): number[][] {
    if (nums.length < 3)
        return []
    nums.sort((x, y) => x - y)
    const ans: number[][] = new Array<number[]>()
    const st: Set<string> = new Set<string>()
    for (let i = 0; i < nums.length - 2; ++i) {
        const target = -nums[i]
        let [left, right] = [i + 1, nums.length - 1]
        while (left < right) {
            if (nums[left] + nums[right] == target) {
                if (!st.has(JSON.stringify([-target, nums[left], nums[right]]))) {
                    st.add(JSON.stringify([-target, nums[left], nums[right]]))
                    ans.push([-target, nums[left], nums[right]])
                }
                ++left
                --right
            } else if (nums[left] + nums[right] < target) {
                ++left
            } else {
                --right
            }
        }
    }
    return ans
};
