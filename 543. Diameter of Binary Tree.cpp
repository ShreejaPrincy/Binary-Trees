// Time Complexity: O(n)
//
// Every node is visited exactly once while calculating height and updating diameter.
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
    int diameter = 0;

    int solve(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left_h = solve(root->left);
        int right_h = solve(root->right);

        diameter = max(diameter, left_h + right_h);

        return max(left_h, right_h) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) { 
        solve(root);
        return diameter; 
    }
};
