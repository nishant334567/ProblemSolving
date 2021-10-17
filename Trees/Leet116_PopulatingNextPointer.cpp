class Solution
{
public:
    Node *connect(Node *root)
    {
        /* Level Order Traversal
        if(!root)
            return root;
        queue<Node*>q;
        q.push(root);
        vector<vector<Node*>>sol;
        while(!q.empty()){
            int l = q.size();
            vector<Node*>v;
            while(l--){
                Node* temp=q.front();
                q.pop();
                v.push_back(temp);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            sol.push_back(v);
        }
        
        for(int i=0;i<sol.size();i++)
        {
            for(int j=0;j<sol[i].size();j++)
            {
                if(j==sol[i].size()-1)
                    sol[i][j]->next=NULL;
                else
                    sol[i][j]->next=sol[i][j+1];
            }
        }
        return root;
        */

        if (!root)
            return root;
        Node *curr, *prev;
        prev = root;

        while (prev->left)
        {
            curr = prev;
            while (curr)
            {
                curr->left->next = curr->right;
                if (curr->next)
                    curr->right->next = curr->next->left;
                curr = curr->next;
            }
            prev = prev->left;
        }
        return root;
    }
};