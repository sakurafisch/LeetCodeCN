function trap(height: number[]): number {
    let ans: number = 0
    const n: number = height.length
    if (Math.floor(n) == 0)
        return ans
    const leftheight = new Array<number>(n)
    const rightheight = new Array<number>(n)
    leftheight[0] = height[0]
    rightheight[n-1] = height[n-1]
    for (let i = 1; i < n; ++i)
        leftheight[i] = Math.max(leftheight[i-1], height[i])
    for (let i = n-2; i >= 0; --i)
        rightheight[i] = Math.max(rightheight[i+1], height[i])
    for (let i = 0; i < n; ++i)
        ans += Math.min(leftheight[i], rightheight[i]) - height[i]
    return ans
};
