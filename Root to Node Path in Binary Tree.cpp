// Time Complexity: O(n)
//
// In the worst case, we may visit every node once while searching for target.
// Therefore, overall time complexity is O(n).
//
// Space Complexity: O(h)
//
// Recursion stack and path can go up to the height of the tree.
// In worst case skewed tree, h = n.
// In balanced tree, h = log n.


class Solution {
  public:
    bool solve(Node* root, vector<int>& path, int target) {
        if(root == NULL) return false;

        path.push_back(root->data);

        if(root->data == target) return true;

        if(solve(root->left, path, target) || solve(root->right, path, target)) {
            return true;
        }

        path.pop_back();
        return false;
    }

    vector<int> rootToNodePath(Node* root, int target) {
        vector<int> path;
        solve(root, path, target);
        return path;
    }
};
