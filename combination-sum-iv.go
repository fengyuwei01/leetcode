package main

import (
	"fmt"
)

// https://leetcode.com/problems/combination-sum-iv/#/description

var (
	C []int
)

func combinationSum4(nums []int, target int) int {
	C = make([]int, target+1)
	C[0] = 1

	for i := 1; i <= target; i++ {
		for _, x := range nums {
			if x <= i {
				C[i] += C[i-x]
			}

			fmt.Println("i,C:", i, C, x)
		}
	}

	return C[target]
}

func main() {
	nums := []int{1, 2, 3}
	sum := combinationSum4(nums, 3)

	fmt.Println("sum:", sum)

	fmt.Println(C)
}
