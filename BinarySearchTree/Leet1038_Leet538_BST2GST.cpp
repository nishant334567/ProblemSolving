/* --------------------------------  1038. Binary Search Tree to Greater Sum Tree --------------------------- 
Given the root of a Binary Search Tree (BST), convert it to a Greater
Tree such that every key of the original BST is changed to the 
original key plus sum of all keys greater than the original key in BST.
*/

/* Reverse inorder traversal */

class Solution {
public:
    int pre=0;
    TreeNode* bstToGst(TreeNode* root) {
        if(root->right) bstToGst(root->right);
        root->val = pre=pre+root->val;
        if(root->left) bstToGst(root->left);
        return root;
    }
};

/* iterative */

TreeNode* convertBST(TreeNode* root)
    {
        if(!root)
            return NULL;
        TreeNode* curr=root;
        stack<TreeNode*>s;
        int sum=0;
        while(curr || !s.empty())
        {
            while(curr)
            {
                s.push(curr);
                curr=curr->right;
            }
            curr=s.top();
            s.pop();
            sum+=curr->val;
            curr->val=sum;
            curr=curr->left;
        }
        return root;
    }
};