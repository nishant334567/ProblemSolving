/* iNTUITION
we have left and right for rvery root, if left and right both are presnt, then that root is lca
otherwise left or right whichever is not null is right */


Node* lca(Node* root ,int n1 ,int n2 )
    {
        if(!root)
            return NULL;
        if(root->data==n1 || root->data==n2)
            return root;
        Node* left = lca(root->left,n1,n2);
        Node* right = lca(root->right,n1,n2);
        if(left && right)
            return root;
        return left!=NULL?left:right;
    }


 bool path(vector<Node*>&v,int n,Node* root)
    {
        if(!root)
            return false;
        v.push_back(root);
        if (root->data == n)
            return true;
        if((root->left && path(v,n,root->left)) || (root->right && path(v,n,root->right)))
            return true;
        v.pop_back();
        return false;
    }
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       vector<Node*>first;
       vector<Node*>second;
       path(first,n1,root);
       path(second,n2,root);
       int a = first.size();
       int b = second.size();
       if(a==0)
        return NULL;
        int i=0;
       while(i<min(a,b) &&(first[i]->data==second[i]->data))
        i++;
        return i>=1?first[i-1]:first[0];
    }