/* --------------------  1877. Minimize Maximum Pair Sum in Array -------------------------------------------*/

/* -------------------------------    Explanation   -------------------------------------------------------


            first we have to make pairs optimally, i.e difference b/w sum of pairs should be kept as low as possible
            1 2 3 4 --> {(1+2),(3+4)} {(1+3)(2+4)} {(1+4)(2+3)}
            If we sort array and add left and right i.e max+min, 
            we control the peak of sum

            
-------------------------------    Explanation   ------------------------------------------------------- */


class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int ans = INT_MIN;
        sort(nums.begin(),nums.end());
        while(l<r)
        {
            ans=max(ans,nums[l]+nums[r]);
            l++;
            r--;
        }
        return ans;
        
    }
};