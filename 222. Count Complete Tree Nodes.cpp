// Time Complexity: O(log^2 n)
//
// At each recursive call, we calculate left height and right height,
// which takes O(log n) time.
// Recursion goes down O(log n) levels in a complete binary tree.
// Therefore, overall time complexity is O(log^2 n).

// Space Complexity: O(log n)
//
// Recursion stack goes up to the height of the complete binary tree.
// Height is O(log n).

class Solution {
public:
    int left_height(TreeNode* root) {
        int h = 0;

        while(root) {
            h++;
            root = root->left;
        }

        return h;
    }

    int right_height(TreeNode* root) {
        int h = 0;

        while(root) {
            h++;
            root = root->right;
        }

        return h;
    }

    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = left_height(root);
        int rh = right_height(root);

        if(lh == rh) {
            return (1 << lh) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
