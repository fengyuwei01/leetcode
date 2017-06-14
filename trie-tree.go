package main

import (
	"fmt"
)

const ALPHA_SIZE = 26 // 字母表

type TrieNode struct {
	count int
	next  [ALPHA_SIZE]*TrieNode // 子节点，最多26个
}

type Trie struct {
	root *TrieNode // 根节点
}

/** Initialize your data structure here. */
func Constructor() Trie {
	return Trie{root: &TrieNode{count: 0}}
}

/** Inserts a word into the trie. */
func (this *Trie) Insert(word string) {
	current := this.root
	for _, c := range word {
		if current.next[c-97] == nil {
			current.next[c-97] = &TrieNode{count: 0}
		}
		current = current.next[c-97]
	}
	current.count += 1
}

/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
	current := this.root
	for _, c := range word {
		if current == nil {
			break
		}
		current = current.next[c-'a']
	}

	return current != nil && current.count > 0
}

/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
	current := this.root
	for _, c := range prefix {
		if current == nil {
			break
		}
		current = current.next[c-'a']
	}

	return current != nil
}

/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */

func main() {
	fmt.Println("hello world")

	var trie = Constructor()
	trie.Insert("a")
	trie.Insert("to")
	trie.Insert("tea")
	trie.Insert("ted")
	trie.Insert("ten")
	trie.Insert("i")
	trie.Insert("in")
	trie.Insert("inn")

	ret := trie.Search("inn")
	fmt.Println("search:", ret)
}
