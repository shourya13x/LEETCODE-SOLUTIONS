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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>vec;
        if(!root){
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        bool flag=1;
        
        while(!q.empty()){
            int n=q.size();
            vector<int>ans(n);
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(flag){
                    ans[i]=node->val;
                }else{
                    ans[n-1-i]=node->val;
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            flag=!flag;
            vec.push_back(ans);
        }
        return vec;
    }
};