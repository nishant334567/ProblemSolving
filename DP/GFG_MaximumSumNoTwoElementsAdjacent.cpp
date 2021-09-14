/* same as maximum sum for 3 consecutives  */
int FindMaxSum(int arr[], int n)
    {
        vector<int>dp(n,0);
        if(n>=1)
            dp[0]=arr[0];
        if(n>=2)
            dp[1]=max(arr[0],arr[1]);
        for(int i=2;i<n;i++)
            dp[i]=max(dp[i-1],arr[i]+dp[i-2]);
      return dp[n-1];  
    }