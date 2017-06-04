// 测试go语言中map 于 slice数据类型
package main

import(
    "fmt"
)

func main() {
    var data = map[string]([]int)
    data = make(map[string]([]int))

    slice := []int{1,2,3}
    data["test"] = slice

    fmt.Println(data) 
}
