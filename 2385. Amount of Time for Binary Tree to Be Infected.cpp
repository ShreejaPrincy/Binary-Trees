// Time Complexity: O(n)
//
// We create parent mapping by visiting every node once.
// We find the start node using BFS.
// Then infection BFS also visits every node once.
// Therefore, overall time complexity is O(n).

// Space Complexity: O(n)
//
// Parent map, visited map, and queue can store up to n nodes.
// Therefore, overall space complexity is O(n).

class Solution {
public:
    void makeParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if(node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

    TreeNode* findStart(TreeNode* root, int start) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node->val == start) return node;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        return NULL;
    }

    int amountOfTime(TreeNode* root, int start) {
        if(root == NULL) return 0;

        unordered_map<TreeNode*, TreeNode*> parent;
        makeParent(root, parent);

        TreeNode* target = findStart(root, start);
        if(target == NULL) return 0;

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;

        q.push(target);
        visited[target] = true;

        int time = -1;

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(parent.find(node) != parent.end() && !visited[parent[node]]) {
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }

                if(node->left && !visited[node->left]) {
                    visited[node->left] = true;
                    q.push(node->left);
                }

                if(node->right && !visited[node->right]) {
                    visited[node->right] = true;
                    q.push(node->right);
                }
            }

            time++;
        }

        return time;
    }
};
