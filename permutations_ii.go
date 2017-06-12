package main

// https://leetcode.com/problems/permutations-ii/#/description
// 回溯法，排列数

import (
	"fmt"
	"sort"
)

var result [][]int

func permuteUnique(nums []int) [][]int {
	result = [][]int{}
	permute(nums, 0)
	return result
}

func permute(nums []int, index int) {
	n := len(nums)

	if index >= n-1 {
		fmt.Println(nums)

		// 复制内存
		tmp1 := make([]int, len(nums))
		copy(tmp1, nums)

		result = append(result, tmp1)
	} else {
		sort.Ints(nums[index:])
		for i := index; i < n; i++ {
			if i != index && nums[i] == nums[i-1] {
				continue
			}

			tmp1 := make([]int, len(nums))
			copy(tmp1, nums)
			swap(&tmp1[index], &tmp1[i])
			permute(tmp1, index+1)
			swap(&tmp1[index], &tmp1[i])

			// swap(&nums[index], &nums[i])
			// permute(nums, index+1)
			// swap(&nums[index], &nums[i])
		}
	}
}

func swap(a *int, b *int) {
	tmp := *a
	*a = *b
	*b = tmp
}

func main() {
	// nums := []int{1, 1, 2}
	//	nums := []int{1, 1, 2, 2}
	nums := []int{0, 1, 0, 0, 9}
	//	permute(nums, 0)
	var result = permuteUnique(nums)
	fmt.Println("result", result)
}
