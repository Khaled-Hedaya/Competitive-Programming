struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == nullptr)
            return nullptr;
        if(root->val == p->val || root->val == q->val)
            return root;
        TreeNode *l = nullptr , *r = nullptr;
        if(root->left)
            l = lowestCommonAncestor(root->left, p, q);
       if(root->right)
            r = lowestCommonAncestor(root->right, p, q);
        if(l && r)
            return root;
        return l ? l : r;
            
    }
};
