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
    void flatten(TreeNode* root) {

        TreeNode* curr = root;

        while (curr != nullptr) {

            if (curr->left != nullptr) {

                // Find the rightmost node of left subtree
                TreeNode* temp = curr->left;

                while (temp->right != nullptr) {
                    temp = temp->right;
                }

                // Connect it to the original right subtree
                temp->right = curr->right;

                // Move left subtree to the right
                curr->right = curr->left;
                curr->left = nullptr;
            }

            // Move to next node
            curr = curr->right;
        }
    }
};