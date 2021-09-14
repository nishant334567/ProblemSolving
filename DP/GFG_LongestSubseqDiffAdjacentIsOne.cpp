/* LIS variation */

int longestSubsequence(int n, int *arr)
    {
        vector<int>dp(n,1);
        int ans = 1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i]-arr[j]==1 || arr[i]-arr[j]==-1)
                    dp[i]=max(dp[i],1+dp[j]);
                ans = max(ans,dp[i]);
            }
        }
        return ans;
    }