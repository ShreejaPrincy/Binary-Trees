// Time Complexity: O(n)
//
// Every node is pushed into and popped from the stack exactly once.
// Therefore, the overall time complexity is O(n).
//
// Space Complexity: O(n)
//
// The stack can store up to n nodes in the worst case.
// Therefore, the overall auxiliary space complexity is O(n).

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        if(root == NULL) {
            return ans;
        }

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            ans.push_back(node->val);

            if(node->right != NULL) {
                st.push(node->right);
            }

            if(node->left != NULL) {
                st.push(node->left);
            }
        }

        return ans;
    }
};
