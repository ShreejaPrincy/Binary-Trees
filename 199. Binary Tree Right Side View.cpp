// Time Complexity: O(n)
//
// Every node is visited once.
// Therefore, overall time complexity is O(n).
//
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,int level,vector<int>&ans){
        if(root==NULL)  return;

        if(ans.size()==level){
            ans.push_back(root->val);
        }
        solve(root->right,level+1,ans);
        solve(root->left,level+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        solve(root,0,ans);
        return ans;
    }
};
