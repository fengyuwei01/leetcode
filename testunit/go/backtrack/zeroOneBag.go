package main

// backtrack法解决01背包问题

import (
	"fmt"
)

const N = 3 // 背包数目

var weight = [N]int{10, 8, 5} // 重量
var price = [N]int{5, 4, 1}   // 价值
var C = 16                    // 当前容量

var (
	best      [N]int // 最好选择
	max_price int    // 最大价值

	current        [N]int // 当前选择
	current_weigth int    // 当前重量
	current_price  int    // 当前价值
)

func backtrack(t int) {
	if t >= N {
		fmt.Println("search_end:", current)
		// 搜索到叶子节点
		if current_price > max_price {
			for i := 0; i < N; i++ {
				best[i] = current[i]
			}
			max_price = current_price
		}
	} else {
		for i := 0; i < 2; i++ {
			// 选择
			current[t] = i
			if i == 0 {
				// 不选择
				current_weigth += 0
				current_price += 0
				backtrack(t + 1)
				// 回溯，其实啥也没做
				current_weigth -= 0
				current_price -= 0
			} else {
				// 选择
				if current_weigth+weight[t] <= C {
					current_weigth += weight[t]
					current_price += price[t]
					backtrack(t + 1)
					// 回溯
					current_weigth -= weight[t]
					current_price -= price[t]
				}
			}
		}
	}
}

func main() {
	backtrack(0)
	fmt.Println("weight:", weight)
	fmt.Println("price:", price)
	fmt.Println("C:", C)
	fmt.Println("best:", best)
	fmt.Println("max_price:", max_price)
}
