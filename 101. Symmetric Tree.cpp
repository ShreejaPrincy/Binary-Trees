// Time Complexity: O(n)
//
// Every node is visited once while comparing mirror positions.
// Therefore, overall time complexity is O(n).
//
// Space Complexity: O(h)
//
// Recursion stack can go up to the height of the tree.
// In worst case skewed tree, h = n.
// In balanced tree, h = log n.

class Solution {
public:
    bool solve(TreeNode* l, TreeNode* r) {
        if(l == NULL && r == NULL) return true;
        if(l == NULL || r == NULL) return false;

        if(l->val != r->val) return false;

        return solve(l->left, r->right) && solve(l->right, r->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return solve(root->left, root->right);
    }
};
