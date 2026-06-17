// Time Complexity: O(n log n)
//
// We visit every node once using BFS.
// For every node, insertion into map and multiset takes logarithmic time.
// Therefore, the overall time complexity is O(n log n).
//
// Space Complexity: O(n)
//
// The map stores all nodes according to their vertical position and level.
// The queue can also store nodes during BFS.
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> mp;

        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            TreeNode* node = front.first;
            int x_value = front.second.first;
            int level = front.second.second;

            mp[x_value][level].insert(node->val);
            if (node->left) {
                q.push({node->left, {x_value - 1, level + 1}});
            }
            if (node->right) {
                q.push({node->right, {x_value + 1, level + 1}});
            }
        }
        for (auto column : mp) {
            vector<int> col;
            for (auto nodes : column.second) {
                col.insert(col.end(),nodes.second.begin(),nodes.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
