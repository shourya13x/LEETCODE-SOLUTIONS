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
    TreeNode* mostright(TreeNode* root) {

        if (root->right == NULL) {
            return root;
        }
        return mostright(root->right);
    }
    TreeNode* helper(TreeNode* root) {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* rightchild = root->right;
        TreeNode* rightmost = mostright(root->left);
        rightmost->right = rightchild;

        TreeNode* temp = root->left;
        delete root;
        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;

        TreeNode* curr = root;
        if (root->val == key) {
            return helper(root);
        }
        while (root != NULL) {
            if (root->val > key) {
                if (root->left != NULL && root->left->val == key) {
                    root->left = helper(root->left);
                } else {
                    root = root->left;
                }
            } else {
                if (root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                } else {
                    root = root->right;
                }
            }
        }
        return curr;
    }
};