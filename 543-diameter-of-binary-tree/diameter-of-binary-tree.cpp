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
int findDepth(TreeNode* root,int& maxi) {
        if (root == NULL) {
            return 0;
        }
        int Lh=findDepth(root->left,maxi);
        int Rh=findDepth(root->right,maxi);
           maxi=max(maxi,Lh+Rh);
        return 1+max(Lh,Rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
      int maxi = 0;
        int x = findDepth(root,maxi);
        return maxi;
       

    }
};