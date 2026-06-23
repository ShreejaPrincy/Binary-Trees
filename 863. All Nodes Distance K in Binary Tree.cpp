//BFS level-wise version
// Create parent mapping for every node to move upward also.
// Start BFS from target node.
// Process BFS level by level; each level represents one distance.
// From every node, move in 3 directions: left, right, and parent.
// Use visited map to avoid revisiting nodes.
// When distance becomes k, all nodes currently in queue are answer.

// Time Complexity: O(n)
// Space Complexity: O(n)

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

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(root == NULL) return ans;

        unordered_map<TreeNode*, TreeNode*> parent;
        makeParent(root, parent);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;

        q.push(target);
        visited[target] = true;

        int dist = 0;

        while(!q.empty()) {
            int size = q.size();

            if(dist == k) break;

            dist++;

            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited[node->left]) {
                    visited[node->left] = true;
                    q.push(node->left);
                }

                if(node->right && !visited[node->right]) {
                    visited[node->right] = true;
                    q.push(node->right);
                }

                if(parent.find(node) != parent.end() && !visited[parent[node]]) {
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
        }

        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};

// Create parent mapping for every node to move upward also.
// Start BFS from target node with distance 0.
// From every node, move in 3 directions: left, right, and parent.
// Use visited map to avoid revisiting nodes and infinite loop.
// If current distance becomes k, add that node to answer.

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    void solve(unordered_map<TreeNode*, TreeNode*>& mp, TreeNode* root) {
        if(root == NULL) return;

        if(root->left) {
            mp[root->left] = root;
            solve(mp, root->left);
        }

        if(root->right) {
            mp[root->right] = root;
            solve(mp, root->right);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(root == NULL) return ans;

        unordered_map<TreeNode*, TreeNode*> mp;
        solve(mp, root);

        queue<pair<TreeNode*, int>> q;
        unordered_map<TreeNode*, bool> visited;

        q.push({target, 0});
        visited[target] = true;

        while(!q.empty()) {
            TreeNode* node = q.front().first;
            int dist = q.front().second;
            q.pop();

            if(dist == k) {
                ans.push_back(node->val);
                continue;
            }

            if(mp.find(node) != mp.end() && !visited[mp[node]]) {
                visited[mp[node]] = true;
                q.push({mp[node], dist + 1});
            }

            if(node->left && !visited[node->left]) {
                visited[node->left] = true;
                q.push({node->left, dist + 1});
            }

            if(node->right && !visited[node->right]) {
                visited[node->right] = true;
                q.push({node->right, dist + 1});
            }
        }

        return ans;
    }
};
