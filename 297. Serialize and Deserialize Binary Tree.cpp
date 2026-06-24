// Time Complexity: O(n)
//
// Every node is visited once during serialization and deserialization.
// Therefore, overall time complexity is O(n).

// Space Complexity: O(n)
//
// Queue and serialized string can store up to n nodes.
// Therefore, overall space complexity is O(n).

class Codec {
public:

    string serialize(TreeNode* root) {
        if(root == NULL) return "";

        string str = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node == NULL) {
                str.append("#,");
            } else {
                str.append(to_string(node->val) + ",");
                q.push(node->left);
                q.push(node->right);
            }
        }

        return str;
    }

    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;

        stringstream ss(data);
        string str;

        getline(ss, str, ',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            getline(ss, str, ',');
            if(str == "#") {
                node->left = NULL;
            } else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(ss, str, ',');
            if(str == "#") {
                node->right = NULL;
            } else {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};
