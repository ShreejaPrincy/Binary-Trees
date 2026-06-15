// Time Complexity: O(n)
//
// Every node is visited exactly once while calculating height and checking balance.
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
    int solve(TreeNode* root) {
        if(root == NULL) return 0;

        int left_height = solve(root->left);
        if(left_height == -1) return -1;

        int right_height = solve(root->right);
        if(right_height == -1) return -1;

        if(abs(left_height - right_height) > 1) return -1;

        return max(left_height, right_height) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return solve(root) != -1;
    }
};
