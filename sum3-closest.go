package main

// https://leetcode.com/problems/3sum-closest/#/description

import (
	"fmt"
	"sort"
)

// f(n) = f(n-1) + a[n] - a[n-3]
// 这个是连续的三个值
// 题目不是要求这个解
func threeSumClosest1(nums []int, target int) int {
	sum := nums[0] + nums[1] + nums[2]
	absDiff := abs(sum, target)
	closeSum := sum
	for i := 3; i < len(nums); i++ {
		sum += nums[i] - nums[i-3]
		if abs(sum, target) < absDiff {
			closeSum = sum
			absDiff = abs(sum, target)
		}
	}
	return closeSum
}

func abs(a int, b int) int {
	if a >= b {
		return a - b
	} else {
		return b - a
	}
}

// 题目要求可以不连续
// 1. i<=j<=k 取三个数
// 2. 固定i，j、k从后面的值从前后进行比较
// 3. 按照最接近的sum值返回
func threeSumClosest(nums []int, target int) int {
	sort.Ints(nums)
	fmt.Println("nums", nums)

	sum := nums[0] + nums[1] + nums[2]
	closest := sum
	n := len(nums)

	for i := 0; i < n-2; i++ {
		j := i + 1
		k := n - 1
		for j < k {
			sum = nums[i] + nums[j] + nums[k]
			if sum == target {
				return sum
			}
			if abs(sum, target) < abs(closest, target) {
				closest = sum
			}
			if sum > target {
				k = k - 1
			} else {
				j = j + 1
			}
		}
	}

	return closest
}
