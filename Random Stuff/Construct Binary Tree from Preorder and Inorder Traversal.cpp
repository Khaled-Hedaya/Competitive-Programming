/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    unordered_map < int , int > indx;
    int j = 0;
    
    TreeNode *construct(int l, int r, vector<int>&p){
        if(l > r) return nullptr;
        int val = p[j++];
        TreeNode* root = new TreeNode(val);
        root->left = construct(l, indx[val] - 1, p);
        root->right = construct(indx[val] + 1 , r, p);
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {    
        int n = (int)preorder.size();      
        for(int i = 0; i < n ; ++i){
            indx[inorder[i]] = i;
        }
        return construct(0 , n - 1, preorder);
    }
};


