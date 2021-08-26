/*  ----------------------------------------  PROBLEM STATEMENT  ------------------------------------------------ 
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.
----------------------------------------------------------------------------------------------------------------- */

/* Alternate robbery h=0,h=2,h=4 etc wiLL pass 50% cases, but its wrong
for cases like [1,2,10000,4,5,6,7] */

/*
रुट पे चोरी करना है या नहीं करना है ये बाद में सोचना, पहले अपने 2 चोर को बोलो पहले एक लेफ्ट जाये और दूसरा राइट जाये 
फिर लेफ़्ट वाला ये बताये की लेफ्ट में Robbery करने पे कितना मिलेगा (  )  और नहीं करने पे कितना मिलेगा (  )
फिर राइट से भी यही करने बोलो

अब रुट के पास 4  values है 
left_rob --> LeftNode में चोरी करके 
right_rob --> RightNode में चोरी करके 
left_without_rob --> LeftNode में बिना चोरी करके 
right_without_rob --> RightNode में बिना चोरी करके

अब रुट आसानी से 2 वvalues निकल सकता है जिसपे पहले वो confused था, चोरी करना है या नहीं
अगर वो रुट पे चोरी करेगा तो वो लेफ्ट और राइट नोड में नहीं कर सकता चोरी 

root_with_rob = root->val + left_without_rob + right_without_rob

अगर वो रुट पे नहीं चोरी करेगा तो वो लेफ्ट और राइट नोड पे चोरी कर सकता या नहीं कर सकता, depends which is a profitable deal

root_without_rob = max(left_rob,left_without_rob) + max(right_rob,right_without_rob)

फाइनल answer root_rob && root_without_rob ka max hoga 

*/


class Solution {
public:
    struct Node
    {
        int with_rob=0;
        int without_rob = 0;
    };
    
    struct Node* rob_(TreeNode* root)
    {
        if(!root)
            return new Node;
        Node* left = rob_(root->left);
        Node* right = rob_(root->right);
        Node* ans = new Node;
        ans->with_rob = root->val+left->without_rob+right->without_rob;
        ans->without_rob = max(left->with_rob,left->without_rob)+max(right->with_rob,right->without_rob);
        return ans;
        
    }
    int rob(TreeNode* root) {
        return max(rob_(root)->with_rob,rob_(root)->without_rob);
    }
};