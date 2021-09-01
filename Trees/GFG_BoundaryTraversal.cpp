/* Boundary traversal of a binary tree in anti-clockwise manner */

/* Intution
    1st thought that came in my mind was to do a level order traversal and print the two extremes of it,
    that is left and the rightmost node
    This good since it will give all the boundary nodes

    -- But problem says it has to be in anticlockwise manner
    so we divide our problem in 4 parts
    1]  print all the left, non-leaf nodes from top2bottom
    2]  print leaf nodes from left to right of left subtree of root
    3]  print leaf nodes from left to right of right subtree of root
    4]  print all the right, non-leaf nodes from bottom2top
 */

class Solution {
public:
    vector<int>sol;
    void print_left(Node* root)
    {
        if(!root || (!root->left && !root->right))
            return;
        
        if(root->left){
            sol.push_back(root->data);
            print_left(root->left);
        }
        
        else if(root->right)
        {
            sol.push_back(root->data);
            print_left(root->right);
        }
    }
    
    void print_leaf(Node* root)
    {
        if(!root)  return;
        print_leaf(root->left);
        if(!root->left && !root->right)
        {
            sol.push_back(root->data);
            return;
        }
        print_leaf(root->right);
    }
    
    void print_right(Node* root)
    {
        if(!root || (!root->left && !root->right))
            return;
        if(root->right){
            print_right(root->right);
            sol.push_back(root->data);
            
        }
        
        else if(root->left)
        {
            print_right(root->left);
            sol.push_back(root->data);
            
        }
        
    }
    vector<int> printBoundary(Node *root)
    {
        //Your code here
        sol.push_back(root->data);
        print_left(root->left);
        print_leaf(root->left);
        print_leaf(root->right);
        print_right(root->right);
        return sol;
    }
};