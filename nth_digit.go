// https://leetcode.com/problems/nth-digit/#/solutions
package main

import (
	"fmt"
	"strconv"
)

func findNthDigit(n int) int {
	// 1. 计算出属于哪个区间，比如 1000~9999
	// 12345 12345 - 9 - 2*90 - 3*900
	base := 1
	digit := 1
	for n-9*base*digit > 0 {
		n = n - 9*base*digit
		base = base * 10
		digit = digit + 1
	}
	// n = n-1
	n = n - 1
	fmt.Println("n", n)

	// 2. 找到当前数的序列
	num := n/digit + base
	fmt.Println("num", num)

	// 3. 找到索引
	index := n % digit
	fmt.Println("index", index)

	// 4. 返回需要的数字
	num_str := strconv.Itoa(num)
	ret := int(num_str[index]) - '0'
	fmt.Println("ret", ret)
	return ret
}

func main() {
	findNthDigit(12345)
}
