/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* temp;
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return root;
        if (root->val == key) {
            if (root->left == nullptr && root->right == nullptr) {
                root = nullptr;
            } else if (root->left == nullptr && root->right != nullptr) {
                root = root->right;
            } else if (root->left != nullptr && root->right == nullptr) {
                root = root->left;
            } else {
                temp = root->left;
                root = root->right;
                if (root->left != nullptr) {
                    TreeNode* tmp = root->left;
                    while (tmp->left != nullptr) {
                        tmp = tmp->left;
                    }
                    tmp->left = temp;
                } else
                    root->left = temp;
            }
            return root;
        }
        if (root->left != nullptr) {
            TreeNode* Left = root->left;
            if (Left->val == key) {
                if (Left->left == nullptr && Left->right == nullptr) {
                    root->left = nullptr;
                } else if (Left->left == nullptr && Left->right != nullptr) {
                    root->left = Left->right;
                } else if (Left->left != nullptr && Left->right == nullptr) {
                    root->left = Left->left;
                } else {
                    temp = Left->left;
                    root->left = Left->right;
                    if (root->left->left != nullptr) {
                        TreeNode* tmp = root->left->left;
                        while (tmp->left != nullptr) {
                            tmp = tmp->left;
                        }
                        tmp->left = temp;
                    } else
                        root->left->left = temp;
                }
                return root;
            } else {
                deleteNode(root->left , key);
            }
        }
        if (root->right != nullptr) {
            TreeNode* Right = root->right;
            if (Right->val == key) {
                if (Right->left == nullptr && Right->right == nullptr) {
                    root->right = nullptr;
                } else if (Right->left == nullptr && Right->right != nullptr) {
                    root->right = Right->right;
                } else if (Right->left != nullptr && Right->right == nullptr) {
                    root->right = Right->left;
                } else {
                    temp = Right->left;
                    root->right = Right->right;
                    if (root->right->left != nullptr) {
                        TreeNode* tmp = root->right->left;
                        while (tmp->left != nullptr) {
                            tmp = tmp->left;
                        }
                        tmp->left = temp;
                    } else
                        root->right->left = temp;
                }
                return root;
            } else
                deleteNode(root->right , key);
        }
        return root;
    }
};