package main

import(
    "fmt"
)

func binarySearch(nums []int,target int) int {
    low := 0
    high := len(nums)-1

    for low <= high {
        mid := (low+high)/2
        fmt.Println(mid, low, high)
        if nums[mid] < target {
            low = mid + 1
        } else if nums[mid] > target {
            high = mid - 1
        } else {
            return mid
        }
    }

    return -1
}

func main() {
    nums := []int{1,2,3,4,5,6,7,8}
    var r = binarySearch(nums,9)
    fmt.Println("r",r)
}

