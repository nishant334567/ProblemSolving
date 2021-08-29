/* --------------------------------  1315. Sum of Nodes with Even-Valued Grandparent  -------------------------------------
Given the root of a binary tree, return the sum of values of nodes with an even-valued grandparent. If there are no nodes with an even-valued grandparent, return 0.
A grandparent of a node is the parent of its parent if it exists. */

/* for very df call what is child wil pe parent and parent will be grandparent
    TC : O(n)
*/
class Solution {
public:
    int ans=0;

    void util(TreeNode* gp,TreeNode* p, TreeNode* child)
    {
        if(!child)
            return;
        if(gp && gp->val%2==0)
            ans+=child->val;
        util(p,child,child->left);
        util(p,child,child->right);
    }
    int sumEvenGrandparent(TreeNode* root) {
        util(NULL,NULL,root);
        return ans;
    }
};


    /*
    void util(TreeNode* root)
    {
        if(!root)
            return;
        if(root->val%2==0)
        {
            if(root->left){
                if(root->left->left)
                    ans+=root->left->left->val;
                if(root->left->right)
                    ans+=root->left->right->val;
            }
            if(root->right)
            {
                if(root->right->left)
                    ans+=root->right->left->val;
                if(root->right->right)
                    ans+=root->right->right->val;
            }
        }
        util(root->left);
        util(root->right);
    }*/