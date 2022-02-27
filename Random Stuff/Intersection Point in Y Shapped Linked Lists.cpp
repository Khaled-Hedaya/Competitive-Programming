// problem link: https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

// Method 1: (Using Two pointers) - O(N + M) Time & O(1) extra space

int intersectPoint(Node* head1, Node* head2)
{
    Node *p1 = head1, *p2 = head2;
    if(!p1 || !p2)
        return -1;
    if(p1 == p2)
        return p1->data;
    while(p1 != p2){
        p1 = p1->next;
        p2 = p2->next;
        if(p1 == p2)
            return p1->data;
        if(!p1) p1 = head2;
        if(!p2) p2 = head1;
    }
    return -1;
}

