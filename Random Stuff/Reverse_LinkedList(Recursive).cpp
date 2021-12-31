
// problem link: https://leetcode.com/problems/reverse-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode *revList(ListNode * curNode){
        if(!curNode) return nullptr;
        
        ListNode *newHead = curNode;
        if(curNode->next){
            newHead = revList(curNode->next);
            curNode->next->next = curNode;
        }
        curNode->next = nullptr;
        return newHead;
    }
    
    ListNode* reverseList(ListNode* head) {
        return revList(head);
    }
};
