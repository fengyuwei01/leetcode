#include<iostream>
// 向量
#include<vector>
#include<map>

// https://leetcode.com/problems/copy-list-with-random-pointer/#/description

/**
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
 
class Solution {
    public:
        RandomListNode *copyRandomList(RandomListNode *head) {
            if (head == NULL) {
                return NULL;
            }
            // 指针-> 序号的映射
            map<RandomListNode *,RandomListNode *> nodeMap;
            // 新头结点
            RandomListNode * newHead = new RandomListNode(head->label);

            // 1.第一遍，复制主链
            RandomListNode * iter = head;
            RandomListNode * prevNode = newHead;

            // 头结点映射
            nodeMap.insert(pair<RandomListNode *,RandomListNode *>(head,newHead));

            iter = iter->next;
            while(iter != NULL) {
                // 复制节点
                RandomListNode * node = new RandomListNode(iter->label);
                prevNode->next = node;
                prevNode = node;

                // 节点映射信息
                nodeMap.insert(pair<RandomListNode *,RandomListNode *>(iter,node));

                // 遍历
                iter = iter->next;
            } 

            // 随机节点复制
            iter = head;
            RandomListNode * newIter = newHead;
            while(iter != NULL) {
                if (NULL!=iter->random) {
                    newIter->random = nodeMap[iter->random];
                }
                iter = iter->next;
                newIter = newIter->next;
            }

            return newHead;
        }
};

int main() {
    std::cout << "hello world" << std::endl;
}
