// Time Complexity: O(n)
//
// Every node is visited and every temporary thread is created and removed once.
// Therefore, overall time complexity is O(n).

// Space Complexity: O(1)
//
// No recursion stack or extra stack is used.
// Only pointers are used.


/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> preOrder(Node* root) {
        vector<int>preorder;
        
        Node* curr=root;
        
        while(curr!=NULL){
            if(curr->left==NULL){
                preorder.push_back(curr->data);
                curr=curr->right;
            }
            else{
                Node* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    preorder.push_back(curr->data);
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return preorder;
    }
};
