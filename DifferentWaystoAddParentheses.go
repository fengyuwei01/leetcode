package main
import (
    "fmt"
    "strconv"
)

// 肯定是用递归做
// https://leetcode.com/problems/different-ways-to-add-parentheses/#/solutions

func diffWaysToCompute(input string) []int {
    length := len(input)
    var r []int
    fmt.Println("input:",input)

    for i:=0;i<length;i++ {
        if input[i]=='+' || input[i]=='-' || input[i]=='*' {
            lr := diffWaysToCompute(input[:i])
            rr := diffWaysToCompute(input[i+1:])
            
            for j := range lr {
                for k := range rr {
                    if input[i] == '+' {
                        r = append(r,lr[j]+rr[k])
                    } else if input[i] == '-' {
                        fmt.Println("compute:",r)
                        r = append(r,lr[j]-rr[k])
                    } else if input[i] == '*' {
                        r = append(r,lr[j]*rr[k])
                    }
                }
            }
        }
    }
    if len(r) == 0 {
        num,_ := strconv.atoi(input)
        r = append(r,num)
        fmt.println("r:",r)
        return r
    }
    return r
}

func diffWaysToCompute1(input string) []int {

}

// 动态规划，把子串和子串的结果存入
func diffWaysToComputeWithDP(intput string,dp map[string][]int) {
}
func main() {
    s := "21"
    r := diffWaysToCompute(s)
    fmt.Println("final:",r) 
}
