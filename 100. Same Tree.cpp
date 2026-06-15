// Time Complexity: O(n)
//
// Every node of both trees is visited once.
// Therefore, the overall time complexity is O(n).
//
// Space Complexity: O(h)
//
// The recursion stack stores at most h nodes,
// where h is the height of the tree.
// In the worst case of a skewed tree, h = n.
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
    bool solve(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL)  return true;

        if(p==NULL || q==NULL)  return false;

        if(p->val != q->val)  return false;

        bool left=solve(p->left,q->left);
        bool right=solve(p->right,q->right);

        return left&&right;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p,q);
    }
};



//clean code

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;

        if(p->val != q->val) return false;

        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
