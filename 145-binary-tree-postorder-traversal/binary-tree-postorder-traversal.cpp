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
        vector<int> post;
        TreeNode* curr = root;
        while (curr) {
            if (curr->right == NULL) {
                post.push_back(curr->val);
                curr = curr->left;
            } else {
                TreeNode* prev =  curr->right;
                while (prev->left && prev->left != curr) {
                    prev = prev->left;
                }
                if (prev->left == NULL) {
                    prev->left = curr;
                    post.push_back(curr->val);
                    curr = curr->right;
                } else {
                    prev->left = NULL;
                    curr = curr->left;
                }
            }
        }
        reverse(post.begin(),
                post.end()); // reversing root->right->left to left->right->root
                             // to make it post order
        return post;
    }
};