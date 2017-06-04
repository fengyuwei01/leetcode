package main

import (
    "fmt"
)

func minWindow(s string, t string) string {
    ls := len(s)
    lt := len(t)
    i := 0
    j := 0
    k := -1
    for i < ls {
        if k < 0 && s[i]==t[j] {
            k = i
        }
        if s[i]==t[j] {
            // fmt.Println(i,j)
            if j == lt-1 {
                break
            } else {
                j++
            }
        }
        i++
    }
    
    if j==lt-1 && k >= 0 {
        fmt.Println(k,i)
        return s[k:i+1]
    }
    return ""
}

func main() {
    s:="ADOBECODEBANC"
    t:="ABC"

    var r = minWindow(s,t)
    fmt.Println(r)
}
