// 1. Recursive Approach

// Time Complexity: O(n)
//
// Every node is visited once.
// Therefore, overall time complexity is O(n).

// Space Complexity: O(h)
//
// Recursion stack can go up to height of tree.
// In worst case skewed tree, h = n.
// In balanced tree, h = log n.

class Solution {
public:
    TreeNode* prev = NULL;

    void flatten(TreeNode* root) {
        if(root == NULL) return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// 2. Iterative Approach using Stack

// Time Complexity: O(n)
//
// Every node is pushed and popped once.
// Therefore, overall time complexity is O(n).

// Space Complexity: O(n)
//
// Stack can store up to n nodes in worst case.
// Therefore, overall space complexity is O(n).


class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);

            if(!st.empty()) node->right = st.top();

            node->left = NULL;
        }
    }
};

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// 3. Morris / O(1) Space Approach

// Time Complexity: O(n)
//
// Every node is visited, and links are rearranged.
// In standard analysis, overall time complexity is O(n).

// Space Complexity: O(1)
//
// No recursion stack or extra stack is used.
// Only pointers are used.

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while(curr != NULL) {
            if(curr->left != NULL) {
                TreeNode* prev = curr->left;

                while(prev->right != NULL) {
                    prev = prev->right;
                }

                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }

            curr = curr->right;
        }
    }
};


---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
