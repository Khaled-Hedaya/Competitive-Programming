// problem link: https://leetcode.com/problems/merge-k-sorted-lists/
// idea : use priority queue with custom comparator to pop the min element from each list

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

class ComparisonClass {
public:
    bool operator() (ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode *dummy = new ListNode();
		ListNode *cur = dummy;
		int sz = (int)lists.size();
		priority_queue<ListNode *, vector<ListNode*>, ComparisonClass> q;
        for(int i = 0 ; i < sz; ++i){
            if(lists[i])
                q.push(lists[i]);
        }
        while(!q.empty()){
            auto f = q.top();
            q.pop();
            cur->next = f;
            cur = cur->next;
            if(f->next)
                q.push(f->next);
        }
        
		cur->next = nullptr;
		return dummy->next;
	}
};
