/* 3 approaches
    dp tc: O(N^2)  SC : O(N)


    original array : sorted array ---> then(LIS)

    TC O(NlogN) SC: O(N)
 */

class Solution {
public:
    /*
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        int maxi = 1;
        dp[0]=1;
        for(int i= 1 ;i < n; i++)
        {
            dp[i]=1;
            for(int k = 0; k<i; k++)
            {
                if(nums[i]>nums[k])
                    dp[i] = max(dp[i],1+dp[k]);
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
        
    }
    */
    int lengthOfLIS(vector<int>& nums) {
        vector<int>temp;
        for(int x:nums)
        {
            if(temp.size()==0 || temp[temp.size()-1]<x)
                temp.push_back(x);
            else{
                auto it = lower_bound(temp.begin(),temp.end(),x);
                *it=x;
            }
        }
        return temp.size();
    }
};