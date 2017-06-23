package main

import (
	"fmt"
)

// https://leetcode.com/problems/spiral-matrix-ii/#/description
// 蜘蛛网状打印数据

// 其实就是找规律
// 数组每层都是一个有规律，n = 4 的话就是 3x4->1x4
// n = 3的话就是2x4 1x1

func generateMatrix(n int) [][]int {

	// 初始化
	ret := make([][]int, n)
	for i := range ret {
		ret[i] = make([]int, n)
	}

	index := 1
	layer := 0
	for i := n - 1; i > 0; i = i - 2 {
		// fmt.Println(i * 4)
		for j := 0; j < i*4; j++ {
			if j < i {
				ret[layer][j+layer] = index
			} else if j < 2*i {
				ret[j-i+layer][n-1-layer] = index
			} else if j < 3*i {
				ret[n-1-layer][i-(j-2*i)+layer] = index
			} else if j < 4*i {
				ret[i-(j-3*i)+layer][layer] = index
			}
			// PrintMatrix(ret)
			// 序号+1
			index += 1
		}
		// 层数+1
		layer += 1
	}
	// 奇数单独处理下
	if n%2 == 1 {
		fmt.Println(1)
		ret[n/2][n/2] = index
	}
	return ret
}

func PrintMatrix(M [][]int) {
	for i := range M {
		fmt.Println(M[i])
	}
}

func main() {
	matrix := generateMatrix(6)
	PrintMatrix(matrix)
}
