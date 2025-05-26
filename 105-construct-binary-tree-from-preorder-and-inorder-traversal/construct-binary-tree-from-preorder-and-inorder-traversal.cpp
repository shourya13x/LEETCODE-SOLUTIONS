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
    TreeNode* buildtree(vector<int>& preorder, vector<int>& inorder, int start,
                        int end, int& idx) {
        if (start > end) {
            return NULL;
        }
        int rootval = preorder[idx];
        int i = start;
        for (; i < end; i++) {
            if (inorder[i] == rootval) {
                break;
            }
        }
        idx++;
        TreeNode* root= new TreeNode(rootval);
        root->left=buildtree(preorder,inorder,start,i-1,idx);
        root->right=buildtree(preorder,inorder,i+1,end,idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0;
        return buildtree(preorder,inorder,0,n-1,idx);
    }
};