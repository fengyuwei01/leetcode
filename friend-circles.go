package main

// https://leetcode.com/problems/friend-circles/#/description
// 其实就是无向图的联通子图个数

// 深度遍历算法
// 找出每个子图出现条件，在那时候加一做统计就好了

// 模拟堆栈
var stack []int
var visit []int

func findCircleNum(M [][]int) int {
	h := len(M)
	// 初始化
	stack = make([]int, h)
	visit = make([]int, h)
	num := 0
	for i := 0; i < h; i++ {
		if visit[i] == 0 {
			depthFirstSearch(M, i)
			num += 1
		}
	}
	return num
}

func depthFirstSearch(M [][]int, start int) int {
	h := len(M)

	index := -1

	// 开始搜索节点
	// start := 0

	// 入栈
	index += 1
	stack[index] = start
	visit[start] = 1

	for {
		top := stack[index]
		i := 0
		for ; i < h; i++ {
			// 遍历相邻节点
			if M[top][i] == 1 && visit[i] == 0 {
				// 入栈
				index += 1
				visit[i] = 1
				stack[index] = i

				break
			}
		}

		if i == h {
			// 遍历完成
			// 退栈
			index -= 1
		}

		if index < 0 {
			break
		}
	}

	return 1
}

func main() {
}
