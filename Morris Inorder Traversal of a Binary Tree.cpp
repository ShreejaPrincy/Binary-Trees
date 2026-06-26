// Time Complexity: O(n)
//
// Every node is visited and every temporary thread is created and removed once.
// Therefore, overall time complexity is O(n).

// Space Complexity: O(1)
//
// No recursion stack or extra stack is used.
// Only pointers are used.


//REMEMBER
/*
If no left child:
    print current
    go right

If left child exists:
    find rightmost node of left subtree

    If thread not made:
        make thread
        go left

    If thread already made:
        remove thread
        print current
        go right
*/

class Solution {
  public:
    vector<int> inOrder(Node* root) {
        vector<int> inorder;
        
        Node* curr = root;
        
        while(curr != NULL) {
            if(curr->left == NULL) {
                inorder.push_back(curr->data);
                curr = curr->right;
            }
            else {
                Node* prev = curr->left;
                
                while(prev->right != NULL && prev->right != curr) {
                    prev = prev->right;
                }
                
                if(prev->right == NULL) {
                    prev->right = curr;
                    curr = curr->left;
                }
                else {
                    prev->right = NULL;
                    inorder.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        
        return inorder;
    }
};
