package main

// https://leetcode.com/problems/longest-substring-without-repeating-characters/#/description

import (
	"fmt"
)

var hashTable = [26]int{}

func lengthOfLongestSubstring(s string) int {
	strlen := len(s)
	maxCount := -1
	for i := 0; i < strlen; i++ {
		hashTable = [26]int{}
		count := 0
		for j := i; j < strlen; j++ {
			// 以j为开始的最大子串
			fmt.Println(j, s[j], s[j]-'a')
			if s[j]-'a' < 0 || s[j]-'a' >= 26 || hashTable[s[j]-'a'] > 0 {
				break
			}
			count += 1
			hashTable[s[j]-'a'] += 1
		}
		if maxCount < count {
			maxCount = count
		}
	}
	return maxCount
}

func main() {
	str := "abcdabcbb"
	max := lengthOfLongestSubstring(str)
	fmt.Println("max", max)
}
