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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s1, s2;
        vector<int> post;
        if (root == NULL)
            return post;
        s1.push(root);
        while (!s1.empty()) {
            TreeNode* root = s1.top();
            s1.pop();
            s2.push(root);
            if (root->left != NULL) {
                s1.push(root->left);
            }
            if (root->right != NULL) {
                s1.push(root->right);
            }
        }
        while (!s2.empty()) {
            post.push_back(s2.top()->val);
            s2.pop();
        }

        return post;
    }
};