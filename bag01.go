package main

// 0-1背包问题动态规划解法
// C[n,w] = max(C[n-1,w],C[n-1,w-wi]+vi)

import (
	"fmt"
)

var (
	// 初始条件
	n = 5
	W = 17
	w = []int{3, 4, 7, 8, 9}
	v = []int{4, 5, 10, 11, 13}

	// 定义
	C = [6][18]int{}
)

// 秀一波英语
func dynamicProgram(weight []int, value []int, n int, W int) int {
	// 固定一行求多列
	for i := 1; i <= n; i++ {
		for w := 1; w <= W; w++ {
			if weight[i-1] > w {
				// 说明物品重量大于总重量
				// 不能选择
				C[i][w] = C[i-1][w]
			} else {
				C[i][w] = max(C[i-1][w], C[i-1][w-weight[i-1]]+value[i-1])
			}
		}
	}
	return C[n][W]
}

func max(a int, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func main() {
	fmt.Println("hello world")
	dynamicProgram(w, v, n, W)
}
