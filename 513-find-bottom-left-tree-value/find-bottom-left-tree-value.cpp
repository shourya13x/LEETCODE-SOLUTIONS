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
    int findBottomLeftValue(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(!root) return 0;
        q.push(root);
        while(!q.empty())
        {
        
                  TreeNode* node=q.front();
                  q.pop();
                  if(node->right!=NULL) q.push(node->right);
                  if(node->left!=NULL) q.push(node->left);
                 ans.push_back(node->val); 
            
        }
        return ans[ans.size()-1];
    }
};