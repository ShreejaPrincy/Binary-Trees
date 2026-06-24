// Time Complexity: O(n)
//
// Every node is created once.
// unordered_map gives root index in O(1).
// Therefore, overall time complexity is O(n).

// Space Complexity: O(n)
//
// unordered_map stores n elements.
// Recursion stack can go up to O(n) in worst case skewed tree.
// Therefore, overall space complexity is O(n).

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
    TreeNode* solve(vector<int>& inorder,int instart,int inend, vector<int>& postorder,int poststart,int postend,unordered_map<int,int>&mp){
        if(poststart>postend || instart>inend)  return NULL;

        int root_val=postorder[postend];
        int root_idx=mp[root_val];
        int left_size=root_idx-instart;

        TreeNode* root=new TreeNode(root_val);

        root->left= solve(inorder,instart,root_idx-1,postorder,poststart,poststart+left_size-1,mp);

        root->right= solve(inorder,root_idx+1,inend,postorder,poststart+left_size,postend-1,mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;

        int n=inorder.size();

        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }

        return solve(inorder,0,n-1,postorder,0,n-1,mp);
    }
};
