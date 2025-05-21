/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getPath(TreeNode* root,TreeNode* value,vector<TreeNode*>&ans)
    {
        if(root==NULL) return false;
        ans.push_back(root);
        if(root==value) return true;
        if(getPath(root->left,value,ans) || getPath(root->right,value,ans))
        {
            return true;
        }
        else{
            ans.pop_back();
            return false;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        vector<TreeNode*> ans1;
         vector<TreeNode*> ans2;
        getPath(root,p,ans1);
        getPath(root,q,ans2);
        
        int i=0;
        TreeNode* lca = NULL;
        while(i<ans1.size() && i< ans2.size()){
            if(ans1[i]==ans2[i])
            {
               lca=ans1[i];
            }
            else{
                break;
            }
            i++;
        }
     return lca;
    }
};