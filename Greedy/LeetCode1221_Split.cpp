
/* ---------------------------    1221. Split a String in Balanced Strings   --------------------------------

Balanced strings are those that have an equal quantity of 'L' and 'R' characters.

Given a balanced string s, split it in the maximum amount of balanced strings.

Return the maximum amount of split balanced strings.

Example 1:

Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", 
each substring contains same number of 'L' and 'R'

*/

/* We have to split it and every splitted part should be balanced
   Example : "LLLRLRRR"
              LLL -- RL -- RRR 
              (not a valid split, since LLL & RRR is not balanced in themselve)
*/

class Solution {
public:
    int balancedStringSplit(string s) {
        int c = 0;
        int ans=0;
        int n = s.size();
        for(int i = 0;i<n;i++)
        {
            if(s[i]=='L')
                c=c-1;
            else
                c+=1;
            if(c==0)
                ans+=1;
        }
        return ans;
    }
};