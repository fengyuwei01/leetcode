package main

import (
	"fmt"
)

// https://leetcode.com/problems/subsets/#/description

// 典型的子集型回溯算法
// 当前节点选择不选择分为两个子节点

var sets [][]int

func subsets(nums []int) [][]int {
	// 初始化
	sets = [][]int{}
	backtrack(nums, 0, []int{})
	return sets
}

func backtrack(nums []int, t int, x []int) {
	if t >= len(nums) {
		// fmt.Println(x)
		xx := make([]int, len(x))
		copy(xx, x)
		sets = append(sets, xx)
	} else {
		for i := 0; i <= 1; i++ {
			if i == 0 {
				// 不选择
				backtrack(nums, t+1, x)
			} else {
				// 选择
				// 这个地方存下来
				x = append(x, nums[t])
				backtrack(nums, t+1, x)
				// 回退
				x = x[:len(x)-1]
			}
		}
	}
}

func main() {
	// x := []int{}

	nums := []int{1, 2, 3}

	s := subsets(nums)

	fmt.Println(s)

}
