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

// Problem link: https://leetcode.com/problems/all-possible-full-binary-trees/


class Solution {
    unordered_map<int, vector<TreeNode *>> vis;

    public:
        vector<TreeNode *> allPossibleFBT(int n) {
            if (vis.find(n) != vis.end()) {
                return vis[n];
            }
            vector<TreeNode *> &ret = vis[n];
            if (n % 2 == 0)
                return ret;
            if (n == 1) {
                ret.push_back(new TreeNode(0));
                return ret;
            }
            for (int l = 1; l < n; l += 2) {
                int r = n - 1 - l;
                vector<TreeNode *> Left = allPossibleFBT(l);
                vector<TreeNode *> Right = allPossibleFBT(r);
                for (auto cntL: Left) {
                    for (auto cntR: Right) {
                        TreeNode *root = new TreeNode(0);
                        root->left = cntL;
                        root->right = cntR;
                        ret.push_back(root);
                    }
                }
            }
            return ret;
        }
};
