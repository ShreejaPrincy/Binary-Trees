// Time Complexity: O(n)
//
// Every node is pushed into and popped from the stacks a constant number of times.
// Therefore, the overall time complexity is O(n).
//
// Space Complexity: O(n)
//
// Two stacks are used, and together they can store up to n nodes.
// Therefore, the overall auxiliary space complexity is O(n).


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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)  return ans;

        stack<TreeNode*>st1;
        stack<TreeNode*>st2;

        st1.push(root);

        while(!st1.empty()){
            TreeNode* node=st1.top();
            st1.pop();
            st2.push(node);

            if(node->left)  st1.push(node->left);
            if(node->right)  st1.push(node->right);
            
        }

        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};
