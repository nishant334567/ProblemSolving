class Solution{
public:	
	int maxSubstring(string s)
	{
	    // Your code goes here
	    int ans = INT_MIN;
	    int n = s.size();
	    int dp[n];
	    memset(dp,0,sizeof(dp));
	    dp[0]=(s[0]=='1')?-1:1;
	    ans = dp[0];
	    for(int i=1;i<n;i++)
	    {
	        if(s[i]=='0')
	        {
	            dp[i]=max(dp[i-1]+1,1);
	        }
	        else{
	            dp[i]=max(dp[i-1]-1,-1);
	        }
	        ans=max(ans,dp[i]);
	    }
	    return ans;
	}
