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
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        vector < vector<int> >ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                root = q.front();
                q.pop();

                if (root->left != NULL)
                    q.push(root->left);
                if (root->right != NULL)
                    q.push(root->right);
                level.push_back(root->val);
            }
            ans.push_back(level);
        }
        return ans.size();
    }
};