function maxArea(height: number[]): number {
    let left = 0, right = height.length-1;
    let ans = 0;
    while (left < right) {
        ans = Math.max(ans, (right - left) * Math.min(height[left], height[right]));
        if (height[left] < height[right]) {
            ++left;
        } else {
            --right;
        }
    }
    return ans;
};
