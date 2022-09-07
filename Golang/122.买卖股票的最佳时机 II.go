package leetcode

func maxProfit(prices []int) int {
	ans := 0
	for i := 1; i < len(prices); i++ {
		ans += maxInt(0, prices[i]-prices[i-1])
	}
	return ans
}

func maxInt(x int, y int) int {
	if x > y {
		return x
	}
	return y
}
