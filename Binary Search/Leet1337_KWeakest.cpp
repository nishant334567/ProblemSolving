/* -------------------------------------  1337. The K Weakest Rows in a Matrix------------------------------------------ */
/*You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.

*/

/* Approach
for every row find their strength using binary search
for every row,s strength, use set of pairs <strength,index> to arrange the values in increasing strength and in case of clash 
will be arranged according to the index */

class Solution {
public:
    int binarySearch(vector<int>&v)
    {
        int count = 0;
        int l=0, r=v.size()-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(v[mid]==1)
            {
                count+=mid-l+1;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return count;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int>sol;
        set<pair<int,int>>s;
        int row=mat.size();
        for(int i =0;i<row;i++)
        {
            int val = binarySearch(mat[i]);
            s.insert({val,i});
        }
        for(auto it:s)
        {
            if(k<=0)
                break;
            sol.push_back(it.second);
            k--;
        }
        return sol;
    }
};