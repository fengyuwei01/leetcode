package main

import "fmt"

func PrintMatrix(M [][]int) {
	for i := range M {
		fmt.Println(M[i])
	}
}

func main() {
	fmt.Println("vim-go")
}
