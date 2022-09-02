function maxChunksToSorted(arr: number[]): number {
    let ans: number = 0
    for (let [i, maxn] = [0, Number.MIN_SAFE_INTEGER]; i < arr.length; ++i) {
        maxn = Math.max(maxn, arr[i])
        if (i == maxn)
            ++ans
    }
    return ans
};
