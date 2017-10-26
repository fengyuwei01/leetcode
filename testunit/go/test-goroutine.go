package main

import (
	"fmt"
	"runtime"
	"time"
)

func test(c chan bool, n int) {

	x := 0
	for i := 0; i < 1000000000; i++ {
		x += i
	}

	println(n, x)

	if n == 9 {
		c <- true
	}
}

func main() {
	runtime.GOMAXPROCS(3) //设置cpu的核的数量，从而实现高并发
	c := make(chan bool)
	start := time.Now()
	for i := 0; i < 10; i++ {
		go test(c, i)
	}
	<-c // 这个地方是在等9号线程运行完成
	end := time.Now()
	cost := end.Sub(start)
	fmt.Println("cost:", cost)
	fmt.Println("main ok")
}
