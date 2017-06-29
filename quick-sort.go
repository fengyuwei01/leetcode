package main

import (
	"fmt"
)

// 快排
// 递归和非递归实现
func quickSort(nums []int, left int, right int) {
	// 选取一个基准
	pivot := left
	if left < right {
		// 划分
		newPivot := partition1(nums, left, right, pivot)
		fmt.Println("partition:", nums[left:right+1])
		fmt.Println("newPivot:", newPivot)
		fmt.Println("----------------")
		quickSort(nums, left, newPivot-1)
		quickSort(nums, newPivot+1, right)
	}
}

// 模仿快排 搜索
func searchKMin(nums []int, left int, right int, k int) int {
	pivot := partition(nums, left, right, 0)
	if pivot == k {
		return nums[pivot]
	} else if pivot > k {
		return searchKMin(nums, left, pivot-1, k)
	} else {
		return searchKMin(nums, pivot+1, right, k)
	}
}

// 划分函数
func partition(nums []int, left int, right int, pivot int) int {
	// 存储位置
	storeIdx := left
	// 交换最后一个元素和基准元素
	swap(&nums[pivot], &nums[right])
	for i := left; i < right; i++ {
		if nums[i] < nums[right] {
			// 交换小于基准的值，并且存储位置加1
			swap(&nums[storeIdx], &nums[i])
			storeIdx += 1
		}
	}
	// 交换基准值到正确位置
	swap(&nums[storeIdx], &nums[right])
	return storeIdx
}

// 改进划分函数
func partition1(nums []int, left int, right int, pivot int) int {
	// 将基准放到最左边
	swap(&nums[left], &nums[pivot])

	i := left
	j := right

	for i != j {
		// 寻找右侧第一个小于基准的值
		for nums[j] >= nums[left] && j > i {
			j = j - 1
		}
		// 寻找左侧第一个大于等于基准的值
		for nums[i] < nums[left] && i < j {
			i = i + 1
		}

		// i不等于j，交换值
		if i != j {
			swap(&nums[i], &nums[j])
		}
	}
	// 将基准值交换到正确位置
	swap(&nums[i], &nums[left])
	return i
}

func swap(a *int, b *int) {
	tmp := *a
	*a = *b
	*b = tmp
}

func main() {
	nums := []int{3, 4, 3, 2, 5, 1, 7}
	fmt.Println(nums)
	quickSort(nums, 0, len(nums)-1)
	fmt.Println(nums)
	fmt.Println("kmin", searchKMin(nums, 0, len(nums)-1, 6))

	fmt.Println("=============")

	nums = []int{3, 5, 4, 7}
	partition1(nums, 0, len(nums)-1, 0)
	fmt.Println(nums)
}
