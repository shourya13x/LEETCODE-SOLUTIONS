/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* node, vector<int>& pre) {
        if (node == NULL)
        {
            pre.push_back(INT_MIN);
             return;
        }
        pre.push_back(node->val);
        helper(node->left, pre);
        helper(node->right, pre);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> pre1,pre2;
        helper(p, pre1);
        helper(q, pre2);
        return pre1==pre2;
    }
};