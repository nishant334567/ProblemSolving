class Solution {
public:
    void inorder(TreeNode* root,vector<int>&sol)
    {
        if(!root)
            return;
        inorder(root->left,sol);
        sol.push_back(root->val);
        inorder(root->right,sol);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>sol;
        inorder(root,sol);
        return sol;
    }
};