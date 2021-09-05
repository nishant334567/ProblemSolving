/* Explanation */
/* for a partition find the max Index of characters occuring in it
traverse to that point count its length */
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>lst(26,0);
        vector<int>res;
        int n = s.size();
        for(int i = 0; i<n;i++)
        {
            lst[s[i]-'a']=i;
        }
        int lastIndex = 0;
        int index=-1;
        for(int i=0;i<n;i++)
        {
            index = max(index,lst[s[i]-'a']);
            if(i==index)
            {
                res.push_back(i-lastIndex+1);
                lastIndex=i+1;
            }
        }
        return res;
    }
};