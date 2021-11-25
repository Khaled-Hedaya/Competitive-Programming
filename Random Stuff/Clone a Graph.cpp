/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// problem's link : https://leetcode.com/problems/clone-graph/

class Solution {    
public:
    
    unordered_map < Node*, Node* > oldTonew;
    
    Node* dfs(Node* root){
        if(oldTonew[root])
            return oldTonew[root];
        
        Node* cpy = new Node(root->val); 
        oldTonew[root] = cpy;
        for(auto child : root->neighbors)
            cpy->neighbors.push_back(dfs(child));
        
        return cpy;
    }
    
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;
        
        Node* copy = dfs(node);
        
        return copy;
    }
};



