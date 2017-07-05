package main

import (
	"fmt"
)

type LinkNode struct {
	PrevNode *LinkNode
	NextNode *LinkNode

	// key值可以直接存在hash中
	key   int
	value int
}

type LFUCache struct {
	hashTable map[int]*LinkNode // hash表
	listHead  *LinkNode         // 双向链表
	listTail  *LinkNode

	capacity int // 容量
	size     int
}

// 初始化
func Constructor(capacity int) LFUCache {
	cache := new(LFUCache)
	// 初始化
	cache.capacity = capacity
	cache.size = 0
	cache.hashTable = make(map[int]*LinkNode, 0)
	cache.listHead = nil
	cache.listTail = nil

	return *cache
}

func (this *LFUCache) Get(key int) int {
	if nil == this.hashTable[key] {
		return -1
	}
	fmt.Print("after:")
	this.PrintList()
	node := this.hashTable[key]
	// 移动节点到头部
	if node != this.listHead {
		node.PrevNode.NextNode = node.NextNode
		if nil != node.NextNode {
			node.NextNode.PrevNode = node.PrevNode
		} else {
			// 尾节点更新
			this.listTail = node.PrevNode
			// fix BUG
			if this.size == 2 {
				this.listTail.PrevNode = node
			}
		}

		node.PrevNode = nil
		node.NextNode = this.listHead
		this.listHead = node
	}
	fmt.Print("get:")
	this.PrintList()
	return node.value
}

func (this *LFUCache) PrintList() {
	node := this.listHead
	for node != nil {
		fmt.Print(node, " ")
		node = node.NextNode
	}
	fmt.Println("")
}

func (this *LFUCache) Put(key int, value int) {
	fmt.Println(this.hashTable)
	if nil == this.hashTable[key] {
		// 超出限制，移除尾节点
		if this.size >= this.capacity {
			// 删除尾节点
			delNode := this.listTail
			fmt.Println("delNode:", delNode)
			this.listTail = delNode.PrevNode
			delete(this.hashTable, delNode.key)

			this.listTail.NextNode = nil
			this.size -= 1
		}

		// 创建
		node := new(LinkNode) // {nil, nil, key, value}

		node.value = value
		node.key = key

		// 替换头结点
		node.NextNode = this.listHead
		if nil != this.listHead {
			this.listHead.PrevNode = node
		}
		this.listHead = node

		// 保存尾节点
		if nil == this.listTail {
			this.listTail = node
			fmt.Println("listTail:", node)
		}

		this.hashTable[key] = node

		fmt.Println("put", this.hashTable[key])
		fmt.Print("before:")
		this.PrintList()

		this.size += 1
	} else {
		// 更新
		node := this.hashTable[key]
		node.value = value
		if node != this.listHead {
			// 尾节点
			if node == this.listTail {
				this.listTail = node.PrevNode
			}
			// 把找到的节点移动到头部
			if this.listHead != node {
				node.PrevNode.NextNode = node.NextNode
				if nil != node.NextNode {
					node.NextNode.PrevNode = node.PrevNode
				} else {
					// 尾节点更新
					this.listTail = node.PrevNode
				}
				node.PrevNode = nil
				node.NextNode = this.listHead
				this.listHead = node
			}
		}
	}
}

func main() {
	cache := Constructor(2)
	cache.Put(1, 1)
	cache.Put(2, 2)
	cache.Get(1)
	cache.Put(3, 3)
	cache.Get(2)
	cache.Get(3)
	cache.Put(4, 4)
	cache.Get(1)
	cache.Get(3)
	cache.Get(4)
}
