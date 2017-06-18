package main

// 扫雷游戏
// https://leetcode.com/problems/minesweeper/#/description

import (
	"fmt"
)

var updatedBoard [][]byte
var visit [][]byte

func updateBoard(board [][]byte, click []int) [][]byte {
	// 初始化
	updatedBoard = make([][]byte, len(board))
	copy(updatedBoard, board)

	visit = make([][]byte, len(board))
	for i := range board {
		visit[i] = make([]byte, len(board[0]))
	}

	// 如果点击mine，不用向下运行
	x := click[0]
	y := click[1]
	if board[x][y] == 'M' {
		updatedBoard[x][y] = 'X'
	} else {
		searchNode(board, x, y)
	}
	return updatedBoard
}

func searchNode(board [][]byte, x int, y int) {
	visit[x][y] = 1

	h := len(board)
	w := len(board[0])

	mineCount := searchMine(board, x, y)
	if mineCount > 0 {
		// 结束条件
		updatedBoard[x][y] = byte(mineCount&0xff) + '0'
	} else {
		updatedBoard[x][y] = 'B'

		// 继续搜索
		startX := 0
		startY := 0

		if x > 0 {
			startX = x - 1
		}
		if y > 0 {
			startY = y - 1
		}

		for i := startX; i < h && i <= x+1; i++ {
			for j := startY; j < w && j <= y+1; j++ {
				if visit[i][j] == 0 {
					searchNode(board, i, j)
				}
			}
		}
	}
}

// 搜索当前点是否有mine
func searchMine(board [][]byte, x int, y int) int {
	startX := 0
	startY := 0

	h := len(board)
	w := len(board[0])

	if x > 0 {
		startX = x - 1
	}
	if y > 0 {
		startY = y - 1
	}

	count := 0
	for i := startX; i < h && i <= x+1; i++ {
		for j := startY; j < w && j <= y+1; j++ {
			if i == x && j == y {
				continue
			}
			if board[i][j] == 'M' {
				count += 1
			}
		}
	}

	return count
}

func PrintMap(board [][]byte) {
	h := len(board)
	w := len(board[0])

	fmt.Print("\n")

	for i := 0; i < h; i++ {
		fmt.Print("|")
		for j := 0; j < w; j++ {
			if j == 0 {
				fmt.Print(" " + string(board[i][j]) + " ")
			} else {
				fmt.Print(string(board[i][j]) + " ")
			}
		}
		fmt.Print("|\n")
	}

	fmt.Print("\n")
}

func main() {
	board := [][]byte{
		{'E', 'E', 'E', 'E', 'E'},
		{'E', 'E', 'M', 'E', 'E'},
		{'E', 'E', 'E', 'E', 'E'},
		{'E', 'E', 'E', 'E', 'E'},
		{'E', 'E', 'E', 'E', 'E'}}

	PrintMap(board)
	updateBoard(board, []int{0, 0})
	//searchMine(board, 0, 0)
	PrintMap(updatedBoard)
	fmt.Println(visit)
}
