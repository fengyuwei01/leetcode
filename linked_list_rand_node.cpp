/**
 * 382. Linked List Random Node
 * Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.
 * Follow up:
 * What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* head;
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
         this->head = head; 
         // 初始化工作
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* cur = this->head;
        int choice = cur->val;
        int i = 1;
        // srand((unsigned)time(NULL));
        do {
            i++;
            // std::cout << "choice:" << choice << ";rand:" << (rand()%i) << std::endl;
            cur = cur->next;
            if((rand()%i)==0 && cur!=NULL) {
                choice = cur->val;
            }
        } while(cur!=NULL && cur->next != NULL);
        
        return choice;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

int main() {
    ListNode* head = NULL;//new ListNode(1);
    // head->next = new ListNode(2);
//    head->next->next =new ListNode(3);
    Solution solution(head);
    int i1=0;
    int i2=0;
    int i3=0;

    for (int i=0;i<1000;i++) {
        int result = solution.getRandom();
        if (result == 1) i1++;
        else if(result == 2) i2++;
        else if(result == 3) i3++;
    }
    std::cout << "i1:" <<i1<< ";i2:"<<i2<<";i3:"<<i3 << std::endl;
}

