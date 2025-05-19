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
    void mapping(TreeNode* root,
                 unordered_map<TreeNode*, TreeNode*>& parent_track,
                 TreeNode* target) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if (current->left) {
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        mapping(root, parent_track, target);
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;
        q.push(target);

        int distance = 0;
        while (!q.empty()) {
            int n = q.size();
            if (distance == k)
                break;
            distance++;
            for (int i = 0; i < n; i++) {

                TreeNode* current = q.front();
                q.pop();
                if (current->left && !visited[current->left]) {
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if (current->right && !visited[current->right]) {
                    q.push(current->right);
                    visited[current->right] = true;
                }

                if (parent_track[current] && !visited[parent_track[current]]) {
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
         vector<int> result;
            while (!q.empty()) {
                TreeNode* current = q.front();
                q.pop();
                result.push_back(current->val);
            }
        return result;
    }
};