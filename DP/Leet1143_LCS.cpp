/* brute force generating all subsequences and comparison
    T.C : O(n*2^n)

    recursive 
    TC : O(2^N)

    dp
    TC: O(mn) 
 */

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int util(int m,int n,string x,string y,vector<vector<int>>&dp)
    {
        if(m<=0 || n<=0)
            return 0;
        if(dp[m][n]!=-1)
            return dp[m][n];
        if(x[m-1]==y[n-1])
            return dp[m][n]=1+util(m-1,n-1,x,y,dp);
        return dp[m][n]=max(util(m,n-1,x,y,dp),util(m-1,n,x,y,dp));
        
    }
    int util_(int x,int y,string X,string Y)
    {
        vector<vector<int>>dp(x+1,vector<int>(y+1,0));
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=y;j++)
            {
                if(X[i-1]==Y[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[x][y];
    }
    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>>dp(x+1,vector<int>(y+1,-1));
        return util_(x,y,s1,s2);
    }
};