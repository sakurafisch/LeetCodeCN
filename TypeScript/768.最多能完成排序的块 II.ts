function maxChunksToSorted(arr: number[]): number {
    let ans: number = 0
    let [sum1, sum2]: number[] = [0, 0]
    const t: number[] = [...arr]
    t.sort((x, y) => x - y)
    for (let i = 0; i < arr.length; ++i) {
        sum1 += arr[i]
        sum2 += t[i]
        if (sum1 === sum2)
            ans += 1
    }
    return ans
};
