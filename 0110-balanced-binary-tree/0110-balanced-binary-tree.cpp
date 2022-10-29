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
    int height(TreeNode *head){
        if(head==NULL)
            return 0;
        int l = height(head->left);
        int r = height(head->right);
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        bool l,r;
        l = isBalanced(root->left);
        r = isBalanced(root->right);
        return l&&r&&(abs(height(root->left)-height(root->right))<=1);
    }
};