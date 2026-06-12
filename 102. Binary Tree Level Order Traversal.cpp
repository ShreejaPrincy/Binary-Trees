// Time Complexity: O(n)
//
// Every node is visited exactly once.
// Therefore, the overall time complexity is O(n).
//
// Space Complexity: O(n)
//
// In the worst case, the queue may store all nodes of the largest level.
// The answer vector also stores all nodes.
// Therefore, the overall space complexity is O(n).

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> level;

            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            ans.push_back(level);
        }

        return ans;
    }
};
