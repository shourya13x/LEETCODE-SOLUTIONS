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
    void helper(TreeNode* root, vector<int>&ans)
  {
       if(root==NULL)
       {
        return;
       }
       helper(root->left,ans);
       ans.push_back(root->val);
       helper(root->right,ans);
  }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
       vector<int> ans;
      helper(root,ans);
      int n= ans.size();
     unordered_set<int> mpp;
     for(int i=0;i<n;i++)
     {
        int remaining =k-ans[i];
        if(mpp.find(remaining)!=mpp.end())
        {
            return true;
        }
       mpp.insert(ans[i]);
     }
     return false;
    }
};