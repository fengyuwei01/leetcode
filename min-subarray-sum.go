package main

// https://leetcode.com/problems/minimum-size-subarray-sum/#/description

// 原来思路
// 朴素思路
func minSubArrayLen_old(s int, nums []int) int {
	length := len(nums)
	minLen := length
	flag := false
	for i := 0; i < length; i++ {
		sum := 0
		for j := i; j < length; j++ {
			sum += nums[j]
			if sum >= s {
				flag = true
				if minLen > (j - i + 1) {
					minLen = j - i + 1
				}
				break
			}
		}
	}
	if flag {
		return minLen
	}
	return 0
}

func minSubArrayLen(s int, nums []int) int {
	// 两指针
	start := 0
	end := 0
	length := len(nums)
	sum := 0
	flag := false
	minLen := length

	for ; end < length; end++ {
		sum += nums[end]
		for sum >= s {
			flag = true
			if minLen > (end - start + 1) {
				minLen = end - start + 1
			}
			sum = sum - nums[start]
			start += 1
		}
	}

	if flag {
		return minLen
	}
	return 0
}
