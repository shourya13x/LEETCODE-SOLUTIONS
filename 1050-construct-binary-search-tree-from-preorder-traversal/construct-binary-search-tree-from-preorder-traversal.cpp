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
    TreeNode* buildtree(vector<int>& preorder, vector<int> inorder,
                        int prestart, int preend, int instart, int inend,
                        unordered_map<int, int> mpp) {
        if (prestart > preend || instart > inend)
            return nullptr;

        TreeNode* currroot = new TreeNode(preorder[prestart]);
        int inroot = mpp[currroot->val];
        int numsleft = inroot - instart;

        currroot->left = buildtree(preorder, inorder, prestart + 1,
                               prestart + numsleft, instart, inroot - 1, mpp);
        currroot->right = buildtree(preorder, inorder, prestart + numsleft + 1,
                                preend, inroot + 1, inend, mpp);

        return currroot;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        unordered_map<int, int> mpp;
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            mpp[inorder[i]] = i;
        }
        return buildtree(preorder, inorder, 0, preorder.size() - 1, 0,
                         inorder.size() - 1, mpp);
    }
};