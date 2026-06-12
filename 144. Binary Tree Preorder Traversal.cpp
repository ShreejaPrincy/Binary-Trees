// Time Complexity: O(n)
//
// Every node is visited exactly once.
// Therefore, the overall time complexity is O(n).
//
// Space Complexity: O(h)
//
// The recursion stack can contain at most h nodes,
// where h is the height of the binary tree.
// In the worst case of a skewed tree, h = n, so space becomes O(n).
// In a balanced tree, h = log n.



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,vector<int>&pre){
        if(root==NULL){
            return;
        }
        pre.push_back(root->val);
        solve(root->left,pre);
        solve(root->right,pre);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>pre;
        solve(root,pre);
        return pre;
    }
};
