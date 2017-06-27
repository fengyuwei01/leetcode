package main

import (
	"fmt"
	"sort"
)

// https://leetcode.com/problems/4sum/#/description

// 思路：先固定两个数，然后用两个指针指向剩余的头结点
// a < b < c <d

var sum4s [][]int

func fourSum(nums []int, target int) [][]int {
	// 排序
	sort.Ints(nums)
	fmt.Println("nums:", nums)
	n := len(nums)

	sum4s = make([][]int, 0)

	for a := 0; a < n-3; a++ {
		for b := a + 1; b < n-2; b++ {
			// 两个指针
			c := b + 1
			d := n - 1
			for c < d {
				sum4 := nums[a] + nums[b] + nums[c] + nums[d]
				if target == sum4 {
					fmt.Println(a, b, c, d)
					sum := []int{nums[a], nums[b], nums[c], nums[d]}
					if !isExist(sum) {
						sum4s = append(sum4s, sum)
					}
					// 跳过此节点
					if c < d-1 {
						c += 1
					} else {
						break
					}
				} else if sum4 < target {
					c += 1
				} else {
					d -= 1
				}
			}
		}
	}

	return sum4s
}

func isExist(sum []int) bool {
	if nil == sum4s {
		return true
	}
	for _, item := range sum4s {
		bol := true
		for i := range sum {
			if sum[i] != item[i] {
				bol = false
				break
			}
		}
		if bol {
			return true
		}
	}
	return false
}

// 废弃方法
func fourSum_old(nums []int, target int) [][]int {
	var sum2 []int
	// 排序
	sort.Ints(nums)
	fmt.Println("nums:", nums)
	n := len(nums)
	sum2 = make([]int, n*n)
	sum4s := make([][]int, 0)

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			sum2[i*n+j] = nums[i] + nums[j]
		}
	}

	li := 0
	lj := 1
	lp := 0*n + 1
	ri := n - 2
	rj := n - 1
	rp := (n-2)*n + n - 1

	for lp < rp {
		sum4 := sum2[lp] + sum2[rp]
		if sum4 == target {
			// 获取结果
			// if lj < ri {
			tmp := []int{nums[li], nums[lj], nums[ri], nums[rj]}
			fmt.Println("tmp", tmp)
			sum4s = append(sum4s, tmp)
			fmt.Println("equal:", li, lj, ri, rj)
			//	}
		}
		// fmt.Println("before:", li, lj, ri, rj)

		if sum4 > target {
			rj -= 1
			if rj <= ri {
				ri -= 1
				rj = ri + 1
			}
			rp = n*ri + rj
		} else {
			lj += 1
			if lj >= n-1 {
				li += 1
				lj = li + 1
			}
			lp = n*li + lj
		}

		// fmt.Println("after:", li, lj, ri, rj)
	}
	PrintMatrix(sum2, 6)
	return sum4s
}
func PrintMatrix(M []int, n int) {
	for i := 0; i < n; i++ {
		for _, j := range M[i*n : i*n+n] {
			fmt.Printf("%3d", j)
		}
		fmt.Println()
	}
}

func main() {
	nums := []int{-3, -2, -1, 0, 0, 1, 2, 3}
	sum4s := fourSum(nums, 0)
	//	fmt.Println(sum4s)
	for i := range sum4s {
		fmt.Println(sum4s[i])
	}
}
