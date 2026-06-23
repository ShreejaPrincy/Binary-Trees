// Time Complexity: O(n)
//
// Every node is created once.
// unordered_map gives root index in O(1).
// Therefore, overall time complexity is O(n).

// Space Complexity: O(n)
//
// unordered_map stores n elements.
// Recursion stack can go up to O(n) in worst case.
// Therefore, overall space complexity is O(n).


class Solution {
public:
    TreeNode* solve(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd,
                    unordered_map<int, int>& mp) {
        
        if(preStart > preEnd || inStart > inEnd) {
            return NULL;
        }

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int rootIndex = mp[rootVal];
        int leftSize = rootIndex - inStart;

        root->left = solve(preorder, preStart + 1, preStart + leftSize,
                           inorder, inStart, rootIndex - 1, mp);

        root->right = solve(preorder, preStart + leftSize + 1, preEnd,
                            inorder, rootIndex + 1, inEnd, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;

        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        int n = preorder.size();

        return solve(preorder, 0, n - 1, inorder, 0, n - 1, mp);
    }
};
