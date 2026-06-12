// Time Complexity: O(n)
//
// Every node is pushed into and popped from the stack exactly once.
// Therefore, the overall time complexity is O(n).
//
// Space Complexity: O(h)
//
// The stack stores nodes along the current root-to-leaf path.
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

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        stack<TreeNode*>st;
        TreeNode*curr=root;

        while(curr!=NULL || !st.empty()){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }

            curr=st.top();
            st.pop();

            ans.push_back(curr->val);
            
            curr=curr->right;
        }
         

        return ans;
    }
};
