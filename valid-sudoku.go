package main

// https://leetcode.com/problems/valid-sudoku/#/description

import (
	"fmt"
)

func isValidSudoku(board [][]byte) bool {
	// 三个规则
	// 1. 每行都是1-9
	// 2. 没列都是1-9
	// 3. 每个子框内都是1-9
	h := len(board)
	w := len(board[0])

	fmt.Println("h&w", h, w)

	if (h != w) || (h%3 != 0) {
		return false
	}

	// 判断 1 2 规则
	for i := 0; i < h; i++ {
		tmp1 := make([]int, h)
		tmp2 := make([]int, h)
		for j := 0; j < h; j++ {
			// 判断行
			if '.' != board[i][j] {
				num1 := int(board[i][j]) - '1'
				if tmp1[num1] > 0 {
					return false
				}
				tmp1[num1] += 1
			}

			// 判断列
			if '.' != board[j][i] {
				num2 := int(board[j][i]) - '1'
				if tmp2[num2] > 0 {
					return false
				}
				tmp2[num2] += 1
			}
		}
	}

	// 判断 3 规则
	tmp3 := make([][]int, 9)
	for i := 0; i < 9; i++ {
		for j := 0; j < 9; j++ {
			index := (i/3)*3 + (j / 3)
			if nil == tmp3[index] {
				tmp3[index] = make([]int, 9)
			}
			if '.' != board[j][i] {
				num := int(board[j][i]) - '1'
				if tmp3[index][num] > 0 {
					return false
				}
				tmp3[index][num] += 1
			}
		}
	}

	return true
}

func main() {
	// board := [][]byte{
	//     {'.', '8', '7', '6', '5', '4', '3', '2', '1'}, //.87654321
	//     {'2', '.', '2', '.', '.', '.', '.', '.', '.'},
	//     {'3', '.', '.', '.', '.', '.', '.', '.', '.'},
	//     {'4', '.', '.', '.', '.', '.', '.', '.', '.'},
	//     {'5', '.', '.', '.', '.', '.', '.', '.', '.'},
	//     {'6', '.', '.', '.', '.', '.', '.', '.', '.'},
	//     {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
	//     {'8', '.', '.', '.', '.', '.', '.', '.', '.'},
	//     {'9', '.', '.', '.', '.', '.', '.', '.', '.'}}
	board := [][]byte{
		{'.', '.', '4', '.', '.', '.', '.', '6', '3'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'5', '.', '.', '.', '.', '.', '.', '9', '.'},
		{'.', '.', '.', '5', '6', '.', '.', '.', '.'},
		{'4', '.', '3', '.', '.', '.', '.', '.', '1'},
		{'.', '.', '.', '7', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '5', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '.', '.', '.', '.'}}

	bol := isValidSudoku(board)
	fmt.Print("ret:", bol)
}
