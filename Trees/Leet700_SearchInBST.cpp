class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {

        /* recursive  */
        if (!root)
            return NULL;
        if (root->val > val)
            return searchBST(root->left, val);
        if (root->val < val)
            return searchBST(root->right, val);
        return root;
        /* recursive ends */

        /* Iterative */
        TreeNode *curr = root;
        while (curr)
        {
            if (curr->val == val)
                return curr;
            else if (curr->val > val)
            {
                curr = curr->left;
            }
            else
                curr = curr->right;
        }
        return NULL;
        /* Iterative ends here */
    }
};