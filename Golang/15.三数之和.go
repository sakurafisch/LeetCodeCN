package leetcode

import "sort"

func threeSum(nums []int) [][]int {
	var ans [][]int
	var st map[[3]int]bool = make(map[[3]int]bool)
	sort.Ints(nums)
	for i := 0; i < len(nums)-2; i++ {
		var target int = -nums[i]
		left, right := i+1, len(nums)-1
		for left < right {
			if nums[left]+nums[right] == target {
				if _, ok := st[[3]int{-target, nums[left], nums[right]}]; !ok {
					st[[3]int{-target, nums[left], nums[right]}] = true
					ans = append(ans, []int{-target, nums[left], nums[right]})
				}
				left++
				right--
			} else if nums[left]+nums[right] < target {
				left++
			} else {
				right--
			}
		}
	}
	return ans
}
