// Time Complexity: O(n)
//
// Every node is visited at most once while searching for p and q.
// Therefore, overall time complexity is O(n).

// Space Complexity: O(h)
//
// Recursion stack can go up to the height of the tree.
// In worst case skewed tree, h = n.
// In balanced tree, h = log n.

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left==NULL)
            return right;
        else if (right==NULL)
            return left;
        else
            return root;
    }
};
