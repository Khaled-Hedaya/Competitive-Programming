// problem link: https://leetcode.com/problems/sort-list/

// note: to find the mid node we use (slow and fast pointer technique -- slow moves by 1 step, fast moves by 2 steps)


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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *mid = getMid(head);
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        return merge(left, right);
    }
    
    ListNode * merge(ListNode *l1, ListNode *l2){
        
        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;
        
        while(l1 && l2){
            if(l1->val < l2->val){
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
        cur->next = (l1 ? l1 : l2);
        return dummy->next;
        
    }
    
    ListNode *getMid(ListNode *root){
        ListNode *prv = nullptr;
        while(root && root->next){
            prv = (prv == nullptr ? root : prv->next);
            root = root->next->next;
        }
        ListNode *mid = prv->next;
        prv->next = nullptr;
        return mid;
    }
    
    
};
