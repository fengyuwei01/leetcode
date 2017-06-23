package main

// https://leetcode.com/problems/longest-uncommon-subsequence-ii/#/description

// 思路：找到不是其他序列的子序列的最长序列

// 判断 target 是否 source 子序列
func isSubsequence(source string, target string) bool {
	ls := len(source)
	lt := len(target)

	i := 0
	j := 0
	for i < ls {
		if source[i] == target[j] {
			// 匹配
			i += 1
			j += 1
		} else {
			i += 1
		}

		if j == lt {
			return true
		}
	}
	return false
}

func findLUSlength(strs []string) int {
	l := len(strs)
	maxLen := -1
	for i := 0; i < l; i++ {
		isRight := true
		for j := 0; j < l; j++ {
			if i == j {
				continue
			}
			// 判断是否是其他字符串的子串
			if isSubsequence(strs[i], strs[j]) {
				isRight = false
				break
			}
		}
		if isRight {
			if maxLen < len(strs[i]) {
				maxLen = len(strs[i])
			}
		}
	}
	return maxLen
}
