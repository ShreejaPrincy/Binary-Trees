// Time Complexity: O(n)
//
// Every node is pushed into and popped from the stack once.
// Therefore, the overall time complexity is O(n).
//
// Space Complexity: O(h)
//
// The stack stores nodes along the current root-to-leaf path.
// In the worst case of a skewed tree, h = n.
// In a balanced tree, h = log n.


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while(curr != NULL || !st.empty()) {
            if(curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
            else {
                TreeNode* temp = st.top()->right;

                if(temp != NULL) {
                    curr = temp;
                }
                else {
                    temp = st.top();
                    st.pop();

                    ans.push_back(temp->val);

                    while(!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();

                        ans.push_back(temp->val);
                    }
                }
            }
        }

        return ans;
    }
};
