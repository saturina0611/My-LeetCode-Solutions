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
vector<int> vt;
    void trace(TreeNode* root) {
        vt.push_back(root->val);
        if(root->left != nullptr) {
            trace(root->left);
        }
        if(root->right != nullptr) {
            trace(root->right);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        trace(root);
        sort(begin(vt) , end(vt));
        int ans = 1000111000;
        for(int i = 0;i < vt.size() - 1;i++) {
            ans = min(ans , vt[i + 1] - vt[i]);
        }
        return ans;
    }
};