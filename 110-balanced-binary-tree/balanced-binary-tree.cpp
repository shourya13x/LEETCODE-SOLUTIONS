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
    int findDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int Lh=findDepth(root->left);
        int Rh=findDepth(root->right);

        return 1+max(Lh,Rh);
    }
    bool isBalanced(TreeNode* root) 
    {
        if(root==NULL) return true;

     int Lh = findDepth(root->left);
      int Rh = findDepth(root->right);
      if(abs(Rh-Lh)>1) return false;
        bool left= isBalanced(root->left);
        bool right= isBalanced(root->right);

        if(!left || !right) return false;


        return true;


    }
};