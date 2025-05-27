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
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int posstart,
                     int posend, int instart, int inend, unordered_map<int, int> &mpp) {
        if (posstart > posend || instart > inend) {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[posend]);
        int inroot=mpp[root->val];
        int numsleft=inroot-instart;
      root->left = helper(inorder, postorder,
                    posstart, posstart + numsleft - 1,
                    instart, inroot - 1, mpp);

root->right = helper(inorder, postorder,
                     posstart + numsleft, posend - 1,
                     inroot + 1, inend, mpp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mpp;
        int n=inorder.size();
        for (int i = 0; i< n; i++) {
            mpp[inorder[i]] = i;
        }
        return helper(inorder,postorder,0,postorder.size()-1,0,inorder.size()-1,mpp);
    }
};