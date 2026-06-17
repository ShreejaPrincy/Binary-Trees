// Time Complexity: O(n log n)
//
// We visit every node once using BFS.
// For every node, insertion/update in map takes log n time.
// Therefore, overall time complexity is O(n log n).
//
// Space Complexity: O(n)
//
// The map stores horizontal distance values.
// The queue can store nodes during BFS.
// Therefore, overall space complexity is O(n).


class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;

        map<int, int> mp;
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while(!q.empty()){
            auto front = q.front();
            q.pop();

            Node* node = front.first;
            int x = front.second;

            mp[x] = node->data;

            if(node->left) q.push({node->left, x - 1});
            if(node->right) q.push({node->right, x + 1});
        }

        for(auto it : mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};
