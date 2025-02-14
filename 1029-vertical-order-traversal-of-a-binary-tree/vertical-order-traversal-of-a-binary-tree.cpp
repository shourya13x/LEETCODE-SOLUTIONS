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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans; 

        queue<pair<TreeNode*,int>> Q; // node and col
        Q.push({root,0});
        int depth=0;
        while(!Q.empty()){
            int s=Q.size();
            while(s--){
                auto [node,col]=Q.front();
                Q.pop();
                ans.push_back({col,depth,node->val});
                if(node->left!=nullptr) Q.push({node->left,col-1});
                if(node->right!=nullptr) Q.push({node->right,col+1});
            }
            depth++;
        }

        sort(ans.begin(),ans.end());

        vector<vector<int>> final;
        vector<int> temp;
        int curr=ans[0][0];
        for(int i=0;i<ans.size();i++){
            if(ans[i][0]==curr) temp.push_back(ans[i][2]);
            else{
                final.push_back(temp);
                temp.clear();
                curr=ans[i][0];
                temp.push_back(ans[i][2]);
            }
        }
        if(!temp.empty()) final.push_back(temp);
        return final;

    }
};