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
    int tot_tilt = 0;
    int helper(TreeNode* root){
        if(root == NULL) return 0;
        int left_tilt = helper(root->left);
        int right_tilt = helper(root->right);
        tot_tilt += abs(left_tilt - right_tilt);
        return root->val+left_tilt+right_tilt;
    }
    int findTilt(TreeNode* root) {
      tot_tilt = 0;
      helper(root);
      return tot_tilt;
    }
};