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
 void helper(TreeNode* node, vector<int> &ans) {
        if (node == NULL) {
            return;
        }
        helper(node->left, ans);
        helper(node->right, ans);
        ans.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* node) {
         vector<int> ans;
        helper(node, ans);
        return ans;
    }
};