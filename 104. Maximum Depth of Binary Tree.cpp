// Time Complexity: O(n)
//
// Every node is visited exactly once.
// Therefore, the overall time complexity is O(n).
//
// Space Complexity: O(h)
//
// The recursion stack stores at most h nodes,
// where h is the height of the tree.
// In the worst case of a skewed tree, h = n.
// In a balanced tree, h = log n.


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return max(lh, rh) + 1;
    }
};
