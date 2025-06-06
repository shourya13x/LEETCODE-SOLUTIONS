class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        int cnt = 0;
        int result = -1;

        while (curr != NULL) {
            if (curr->left == NULL) {
                // Visit current node
                cnt++;
                if (cnt == k) result = curr->val;
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right != NULL && prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    // Make thread
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    // Remove thread and visit current
                    prev->right = NULL;

                    cnt++;
                    if (cnt == k) result = curr->val;

                    curr = curr->right;
                }
            }
        }

        return result;
    }
};