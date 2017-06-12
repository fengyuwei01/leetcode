package main

// https://leetcode.com/problems/word-search/#/description

import (
	"fmt"
)

// 判断字符串是否存在迷宫中
func exist(board [][]byte, word string) bool {

	h := len(board)
	w := len(board[0])

	visit := make([][]int, h)
	for i := range visit {
		var line = make([]int, w)
		for j := range line {
			line[j] = 0
		}
		visit[i] = line
	}

	fmt.Println("visit:", visit)
	ret := false

	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			if board[i][j] == byte(word[0]) {
				fmt.Println("begin:", i, j)
				ret = ret || backtrack(board, i, j, word, 0, visit)
			}
		}
	}
	return ret
}

func backtrack(board [][]byte, x int, y int, word string, index int, visit [][]int) bool {

	visit[x][y] = 1

	h := len(board)
	w := len(board[0])
	ret := false

	if index >= (len(word) - 1) {
		ret = true
	} else {
		if x-1 >= 0 && board[x-1][y] == word[index+1] && visit[x-1][y] == 0 {
			ret = ret || backtrack(board, x-1, y, word, index+1, visit)
		}
		if y-1 >= 0 && board[x][y-1] == word[index+1] && visit[x][y-1] == 0 {
			ret = ret || backtrack(board, x, y-1, word, index+1, visit)
		}
		if x+1 < h && board[x+1][y] == word[index+1] && visit[x+1][y] == 0 {
			ret = ret || backtrack(board, x+1, y, word, index+1, visit)
		}
		if y+1 < w && board[x][y+1] == word[index+1] && visit[x][y+1] == 0 {
			ret = ret || backtrack(board, x, y+1, word, index+1, visit)
		}
	}

	// 回退
	visit[x][y] = 0
	return ret
}

func main() {
	// board := [][]byte{
	//     {'A', 'B', 'C', 'E'},
	//     {'S', 'F', 'C', 'S'},
	//     {'A', 'D', 'E', 'E'}}
	// bol := exist(board, "ABCCED")

	// board := [][]byte{
	//     {'a', 'a'}}
	// bol := exist(board, "aaa")

	board := [][]byte{
		{'C', 'A', 'A'},
		{'A', 'A', 'A'},
		{'B', 'C', 'D'}}
	bol := exist(board, "AAB")

	fmt.Println("result:", bol)
}
