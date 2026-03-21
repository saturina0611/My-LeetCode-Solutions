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
    bool findTarget(TreeNode* root, int k) {
        trace(root);
        sort(begin(vt) , end(vt));
        int left = 0 , right = vt.size() - 1;
        for(left = 0;left < right;left++) {
            if(left == (int)vt.size()) return false;
            if(right < 0) return false;
            while(left < (int)vt.size() && right >= 0 && vt[left] + vt[right] > k && left < right) {
                right--;
                if(left == (int)vt.size() || right < 0 || right <= left) break;
            }
            if(vt[left] + vt[right] == k && left != right) return true;
        }
        return false;
    }
};