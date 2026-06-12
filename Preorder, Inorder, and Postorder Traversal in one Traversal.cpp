// Time Complexity: O(n)
//
// Every node is processed three times:
// once for preorder, once for inorder, and once for postorder.
// Since 3n is simplified to n, the overall time complexity is O(n).
//
// Space Complexity: O(n)
//
// The stack can store up to O(n) node-state pairs in the worst case.
// The three result vectors also store node values.
// Therefore, the overall auxiliary space complexity is O(n).

class Solution {
public:
    void allTraversals(TreeNode* root, vector<int>& preorder, vector<int>& inorder, vector<int>& postorder) {
      
      if(root==NULL)  return;

      stack<pair<TreeNode*,int>>st;
      st.push({root,1});

      while(!st.empty()){
        auto it=st.top();
        st.pop();

        if(it.second==1){
          preorder.push_back(it.first->val);
          it.second++;
          st.push(it);

          if(it.first->left)  st.push({it.first->left,1});
        }
        else if(it.second==2){
          inorder.push_back(it.first->val);
          it.second++;
          st.push(it);

          if(it.first->right)  st.push({it.first->right,1});
        }
        else{
          postorder.push_back(it.first->val);
        }
      }
      
    }
};
