// Time Complexity: O(n * h)
//
// We visit every node once, and path string copying can take up to O(h).
// Therefore, overall time complexity is O(n * h).
//
// Space Complexity: O(h)
//
// Recursion stack can go up to height of tree.
// The answer vector is not counted in auxiliary space.

class Solution {
public:
    void solve(TreeNode* root, string temp, vector<string>& ans) {
        if(root == NULL) return;

        if(temp.empty()) {
            temp += to_string(root->val);
        } else {
            temp += "->" + to_string(root->val);
        }

        if(root->left == NULL && root->right == NULL) {
            ans.push_back(temp);
            return;
        }

        solve(root->left, temp, ans);
        solve(root->right, temp, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(root, "", ans);
        return ans;
    }
};
