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
    vector<int> res;
    unordered_map<int,int> mp;
    void check(TreeNode* root,int n){
        if(!root){
            return;
        }
        if(!(mp.find(n) != mp.end())){
            res.push_back(root->val);
            mp[n]++;
        }
        check(root->right,n+1);
        check(root->left,n+1);
    }
    vector<int> rightSideView(TreeNode* root) {
      check(root,0);
      return res;  
    }
};