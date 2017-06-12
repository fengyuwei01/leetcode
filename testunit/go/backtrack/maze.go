// 迷宫问题，backtrack解法
package main

import (
	"fmt"
)

const N = 10

const ENTER_X = 0 //入口的位置（0，0）
const ENTER_Y = 0
const EXIT_X = N - 1 //出口的位置(N-1,N-1)
const EXIT_Y = N - 1

// 迷宫
var Maze = [N][N]int{
	{0, 0, 1, 1, 1, 1, 1, 1, 1, 1}, //0
	{1, 0, 0, 1, 1, 0, 0, 1, 0, 1}, //1
	{1, 0, 0, 1, 0, 0, 0, 1, 0, 1}, //2
	{1, 0, 0, 0, 0, 1, 1, 0, 0, 1}, //3
	{1, 0, 1, 1, 1, 0, 0, 0, 0, 1}, //4
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 1}, //5
	{1, 0, 1, 0, 0, 0, 1, 0, 0, 1}, //6
	{1, 0, 1, 1, 1, 0, 1, 1, 0, 1}, //7
	{1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //8
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 0}} //9
//   0  1  2  3  4  5  6  7  8  9

func maze_track(x int, y int) {
	Maze[x][y] = 2
	if x == EXIT_X && y == EXIT_Y {
		// 找到出口
		fmt.Println("find a way:")
		fmt.Println("--------------------------------")
		for i := 0; i < N; i++ {
			fmt.Println(Maze[i])
		}
		fmt.Println("--------------------------------")
	} else {
		//	Maze[x][y] = 2

		if x-1 >= 0 && Maze[x-1][y] == 0 {
			// 左
			maze_track(x-1, y)
		}

		if y-1 >= 0 && Maze[x][y-1] == 0 {
			// 上
			maze_track(x, y-1)
		}

		if x+1 < N && Maze[x+1][y] == 0 {
			// 右
			maze_track(x+1, y)
		}

		if y+1 < N && Maze[x][y+1] == 0 {
			// 下
			maze_track(x, y+1)
		}
		// 都不通,回退
		// Maze[x][y] = 0
	}
	Maze[x][y] = 0
}

func main() {
	maze_track(0, 0)
}
