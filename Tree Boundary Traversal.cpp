// Time Complexity: O(n)
//
// Every node is visited at most a constant number of times while collecting
// the left boundary, leaf nodes, and right boundary.
// Therefore, the overall time complexity is O(n).
//
// Space Complexity: O(h)
//
// The recursion stack can go up to the height of the tree.
// In the worst case of a skewed tree, h = n.
// In a balanced tree, h = log n.

/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void left_nodes(Node *node,vector<int>&ans){
        if(node == NULL) return;
        if(node->left==NULL && node->right==NULL){
            return;
        }
        ans.push_back(node->data);
        if(node->left)
            left_nodes(node->left,ans);
        else
            left_nodes(node->right,ans);
    }
    void leaf_nodes(Node *node,vector<int>&ans){
        if(node==NULL)  return;
        if(node->left==NULL && node->right==NULL){
            ans.push_back(node->data);
            return;
        }
        leaf_nodes(node->left,ans);
        leaf_nodes(node->right,ans);
    }
    void right_nodes(Node *node,vector<int>&ans){
        if(node==NULL)  return;
        if(node->left==NULL && node->right==NULL){
            return;
        }
        
        if(node->right)
            right_nodes(node->right,ans);
        else
            right_nodes(node->left,ans);
            
        ans.push_back(node->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        vector<int>ans;
        if(root==NULL)  return ans;
        
        ans.push_back(root->data);
        
        left_nodes(root->left,ans);
        
        leaf_nodes(root->left,ans);
        leaf_nodes(root->right,ans);
        
        right_nodes(root->right,ans);
        return ans;
    }
};


//clean code

class Solution {
  public:
    bool isLeaf(Node* node) {
        return node->left == NULL && node->right == NULL;
    }

    void left_nodes(Node* node, vector<int>& ans) {
        if(node == NULL) return;

        if(isLeaf(node)) return;

        ans.push_back(node->data);

        if(node->left)
            left_nodes(node->left, ans);
        else
            left_nodes(node->right, ans);
    }

    void leaf_nodes(Node* node, vector<int>& ans) {
        if(node == NULL) return;

        if(isLeaf(node)) {
            ans.push_back(node->data);
            return;
        }

        leaf_nodes(node->left, ans);
        leaf_nodes(node->right, ans);
    }

    void right_nodes(Node* node, vector<int>& ans) {
        if(node == NULL) return;

        if(isLeaf(node)) return;

        if(node->right)
            right_nodes(node->right, ans);
        else
            right_nodes(node->left, ans);

        ans.push_back(node->data);
    }

    vector<int> boundaryTraversal(Node* root) {
        vector<int> ans;

        if(root == NULL) return ans;

        if(!isLeaf(root)) {
            ans.push_back(root->data);
        }

        left_nodes(root->left, ans);

        leaf_nodes(root, ans);

        right_nodes(root->right, ans);

        return ans;
    }
};
