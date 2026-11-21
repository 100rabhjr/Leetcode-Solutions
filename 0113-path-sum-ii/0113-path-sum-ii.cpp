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
int sum = 0;
void allpaths(TreeNode* root,int targetSum,vector<int> &arr ,vector<vector<int>>&ans){
    if (root == NULL) return;

    sum+=root->val;
    arr.push_back(root->val);    

    if(root->left == NULL && root->right == NULL && sum == targetSum){
        ans.push_back(arr);
    }
    else {
            allpaths(root->left, targetSum, arr, ans);
            allpaths(root->right, targetSum, arr, ans);
        }
        sum -= root->val;
        arr.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        sum = 0;
       vector<int>arr;
       vector<vector<int>>ans;
       allpaths(root,targetSum,arr,ans);
       return ans; 
    }
};