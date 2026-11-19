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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

    int lh = 0, rh = 0;
    TreeNode* leftNode = root;
    TreeNode* rightNode = root;
    while (leftNode != NULL) {
        lh++;
        leftNode = leftNode->left;
    }
    while (rightNode != NULL) {
        rh++;
        rightNode = rightNode->right;
    }
    if (lh == rh) {
        return (1 << lh) - 1; // 2^lh - 1
    }
        int leftCnt = countNodes(root->left);
        int rightCnt = countNodes(root->right);
        return (leftCnt+rightCnt)+1;
    }
};