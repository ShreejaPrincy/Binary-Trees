// Time Complexity: O(n)
//
// Every node is visited exactly once.
// Reversing each level also touches each node at most once across all levels.
// Therefore, the overall time complexity is O(n).// Space Complexity: O(n)
//
// The queue can store nodes of a level in the worst case.
// The answer vector stores all node values.
// Therefore, the overall space complexity is O(n).


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if (root == NULL) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool l_to_r = true;

        while (!q.empty()) {

            int size = q.size();
            vector<int> level;

            for (int i = 0; i<size; i++) {

                TreeNode* node = q.front();
                q.pop();
                
                level.push_back(node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (l_to_r == false) {
                reverse(level.begin(), level.end());
            }
            ans.push_back(level);
            l_to_r = !l_to_r;
        }
        return ans;
    }
};
