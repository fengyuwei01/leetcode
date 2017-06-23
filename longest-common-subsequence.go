package main

import (
	"fmt"
)

// 最长公共子序列
// 经典动态规划解法
// dp[i][j] = dp[i-1][j-1] + 1 如果 a[i] == b[j]
// dp[i][j] = max( dp[i-1][j], dp[i][j-1] ) 如果 a[i] != b[j]

var dp [][]int

func longestCommonSubsequence(a string, b string) int {
	m := len(a)
	n := len(b)

	// 初始化数组
	dp = make([][]int, m+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
	}

	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			fmt.Println("i,j", i, j)
			fmt.Println("dp", dp)
			if a[i-1] == b[j-1] {
				dp[i][j] = dp[i-1][j-1] + 1
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1])
			}
		}
	}

	return dp[m][n]
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

	a := "a"
	b := "ab"

	cnt := longestCommonSubsequence(a, b)

	fmt.Println("cnt", cnt)

}
