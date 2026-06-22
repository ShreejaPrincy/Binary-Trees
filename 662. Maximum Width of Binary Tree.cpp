// Time Complexity: O(n)
//
// Every node is visited once using BFS.
// Therefore, overall time complexity is O(n).

// Space Complexity: O(n)
//
// Queue can store nodes of one level.
// In the worst case, this can be O(n).

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)  return 0;

        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        
        long long max_width=0; 

        while(!q.empty()){

            long long size=q.size();

            long long min_i=q.front().second;
            long long first,last;

            for(long long i=0;i<size;i++){

                TreeNode* node=q.front().first;
                long long index=q.front().second-min_i;
                q.pop();

                if(i==0)        first=index;
                if(i==size-1)   last=index;

                if(node->left)      q.push({node->left,2*index+1});
                if(node->right)     q.push({node->right,2*index+2});
            }
            max_width=max(max_width,last-first+1);
        }
        return (int)max_width;
    }
};
