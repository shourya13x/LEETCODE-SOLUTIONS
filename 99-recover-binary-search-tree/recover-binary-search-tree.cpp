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
    void helper(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }
        helper(root->left, ans);
        ans.push_back(root->val);
        helper(root->right, ans);
    }
  void updateHelper(TreeNode* root,vector<int>&ans,int& i)
  {
    if(root==NULL) return;
    updateHelper(root->left,ans,i);
    root->val=ans[i++];
    updateHelper(root->right,ans,i);

  }
    void recoverTree(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        sort(ans.begin(), ans.end());
        int i = 0;
     updateHelper(root,ans,i);
    }
};