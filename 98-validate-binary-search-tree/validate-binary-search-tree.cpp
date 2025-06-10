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
    bool validtreechecker(TreeNode* root, long long INTMIN, long long INTMAX) {
        if (root == NULL)
            return true;
        if (root->val >= INTMAX || root->val <= INTMIN)
            return false;

        return validtreechecker(root->left, INTMIN, root->val)
        && validtreechecker(root->right, root->val, INTMAX);
    }
    bool isValidBST(TreeNode* root) {
        return validtreechecker(root, LLONG_MIN, LLONG_MAX);
    }
};