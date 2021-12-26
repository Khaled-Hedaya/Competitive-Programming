// problem link: https://leetcode.com/problems/subtree-of-another-tree/
// required: check if a tree is a subtree of another one



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
    
    bool sameTree(TreeNode *r1 , TreeNode *r2){
        if(!r1 && !r2)
            return true;
        if(!r1 || !r2)
            return false;
        if(r1->val != r2->val) return false;
        return sameTree(r1->left, r2->left) && sameTree(r1->right, r2->right); 
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if(!root) return false;
        if(sameTree(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};






