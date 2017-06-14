package main

import (
	"fmt"
	"os"
)

//func TestAlloc(t *testing.T) {
func TestAlloc() {
	type T struct {
		n  string
		i  int
		f  float64
		fd *os.File
		b  []byte
		s  bool
	}

	var t1 *T
	t1 = new(T)
	fmt.Println(t1)

	t2 := T{}
	fmt.Println(t2)

	t3 := T{"hello", 1, 3.1415926, nil, make([]byte, 2), true}
	fmt.Println(t3)
}

func main() {
	TestAlloc()

	// &{ 0 0 <nil> [] false}
	// { 0 0 <nil> [] false}
	// {hello 1 3.1415926 <nil> [0 0] true}
}
