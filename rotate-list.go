package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

// 节点结构体
type ListNode struct {
	Val  int
	Next *ListNode
}

var stack []*ListNode

func rotateRight(head *ListNode, k int) *ListNode {
	if nil == head || head.Next == nil || k == 0 {
		return head
	}
	stack = []*ListNode{}
	index := head

	// 遍历入栈
	for index != nil {
		stack = append(stack, index)
		index = index.Next
	}
	l := len(stack)

	// 尾节点
	tail := stack[l-1]
	tail.Next = head

	// 找到栈 k 之前的节点
	tmp := stack[(l-(k+1)%l)%l]

	// 切断
	kIndex := tmp.Next
	// 这个很重要
	tmp.Next = nil

	return kIndex
}

// 超时算法
func rotateRight_old(head *ListNode, k int) *ListNode {
	index := head
	for i := 0; i < k; i++ {
		index = rotateRightByStep(index)
	}
	return index
}

func rotateRightByStep(head *ListNode) *ListNode {
	if nil == head || head.Next == nil {
		return head
	}

	index := head
	for index.Next.Next != nil {
		index = index.Next
	}
	tail := index.Next

	tail.Next = head
	index.Next = nil

	return tail
}

func main() {
	var tail *ListNode = &ListNode{9, nil}
	prev = tail
	var index = nil
	for i := 8; i > 0; i-- {
		index = ListNode{i, prev}
		prev = index
	}
	head = index
}
