// Time Complexity: O(n)
//
// Every node is visited exactly once while calculating the maximum path sum.
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
    int sum = INT_MIN;

    int solve(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int left_sum = max(0, solve(root->left));
        int right_sum = max(0, solve(root->right));

        sum = max(sum, left_sum + right_sum + root->val);

        return root->val + max(left_sum, right_sum);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return sum;
    }
};
