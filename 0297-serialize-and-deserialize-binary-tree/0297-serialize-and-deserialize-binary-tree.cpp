/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void serializeHelper(TreeNode* root, string& s) {

        if (root == nullptr) {
            s += "# ";
            return;
        }

        s += to_string(root->val) + " ";

        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    string serialize(TreeNode* root) {

        string s;

        serializeHelper(root, s);

        return s;
    }

    TreeNode* deserializeHelper(stringstream& ss) {

        string value;
        ss >> value;

        if (value == "#") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(value));

        root->left = deserializeHelper(ss);
        root->right = deserializeHelper(ss);

        return root;
    }

    TreeNode* deserialize(string data) {

        stringstream ss(data);

        return deserializeHelper(ss);
    }
};