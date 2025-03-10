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
int diameter=0;
int findDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int Lh=findDepth(root->left);
        int Rh=findDepth(root->right);
         diameter = max(diameter,Lh+Rh);
        return 1+max(Lh,Rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        findDepth(root);
        return diameter;
    }
};