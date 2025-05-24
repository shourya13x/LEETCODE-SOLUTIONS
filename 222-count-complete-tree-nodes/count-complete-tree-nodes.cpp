class Solution {
public:
    // Walk left-most path to get height
    int getLeftHeight(TreeNode* node) {
        int h = 0;
        while (node) {
            h++;
            node = node->left;
        }
        return h;
    }

    // Walk right-most path to get height
    int getRightHeight(TreeNode* node) {
        int h = 0;
        while (node) {
            h++;
            node = node->right;
        }
        return h;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int lh = getLeftHeight(root);
        int rh = getRightHeight(root);

        if (lh == rh) {
            // Perfect binary tree: total nodes = 2^h - 1
            return (1 << lh) - 1;
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};
