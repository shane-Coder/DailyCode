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
    int res = 0;
    void solve(TreeNode* head){
        if(head==NULL)
            return ;
        if(head->left and !head->left->left and !head->left->right)
            res += head->left->val;
        solve(head->left);
        solve(head->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        // TreeNode *head = root;
        solve(root);
        return res;
    }
};