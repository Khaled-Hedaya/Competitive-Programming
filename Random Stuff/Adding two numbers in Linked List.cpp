#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 1e5 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}
};

/*
You are given two non-empty linked lists representing two non-negative integers.
"The digits are stored in reverse order", and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.
*/
// problem link: https://leetcode.com/explore/interview/card/top-interview-questions-medium/107/linked-list/783/

class Solution {
public:

    int getLength(ListNode *head, ListNode *&prv) {
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
            if (head)
                prv = head;
        }
        return len;
    }

    void updateLength(int &len1, const int &len2, ListNode *&prv) {
        while (len1 < len2) {
            ++len1;
            ListNode *cur = new ListNode(0);
            prv->next = cur;
            prv = prv->next;
        }
    }

    void calculateSum(ListNode *l1, ListNode *l2, ListNode *&dummy, int &carry) {
        while (l1) {
            int val1 = l1->val;
            int val2 = l2->val;
            ListNode *cur;
            if (val1 + val2 + carry <= 9) {
                cur = new ListNode(val1 + val2 + carry);
                carry = 0;
            } else {
                int sum = val1 + val2 + carry;
                int digit = sum % 10;
                carry = sum / 10;
                cur = new ListNode(digit);
            }
            dummy->next = cur;
            dummy = dummy->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (carry) {
            dummy->next = new ListNode(carry);
            dummy = dummy->next;
        }
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int len1 = 0;
        int len2 = 0;
        ListNode *prv1 = l1, *prv2 = l2;

        len1 = getLength(l1, prv1);
        len2 = getLength(l2, prv2);

        updateLength(len1, len2, prv1);
        updateLength(len2, len1, prv2);

        ListNode *newHead = new ListNode();
        ListNode *dummy = newHead;
        
        int carry = 0;
        calculateSum(l1, l2, dummy, carry);

        return newHead->next;
    }
};


int main() {
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif
    
    // call here function: addTwoNumbers(list1 , list2) 

    return 0;
}
