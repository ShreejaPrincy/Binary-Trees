// Time Complexity: O(n)
//
// Every node is visited once.
// Therefore, overall time complexity is O(n).

// Space Complexity: O(h)
//
// Recursion stack can go up to the height of the tree.
// In worst case skewed tree, h = n.
// In balanced tree, h = log n.

class Solution {
  public:
    bool isSumProperty(Node *root) {
        if(root == NULL) return true;

        if(!root->left && !root->right) return true;
        
        int left = 0;
        int right = 0;
        
        if(root->left) left = root->left->data;
        if(root->right) right = root->right->data;
        
        if(root->data != left + right) return false;
        
        return isSumProperty(root->left) && isSumProperty(root->right);
    }
};
