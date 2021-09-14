/* follow up for no two adjacent element */

int MaxSumNoThreeAdjacent(int *arr,int n)
{
    int dp[n];
    if(n>=1)
        dp[0]=arr[0];
    if(n>=2)
        dp[1]=arr[1];
    if(n>2)
        dp[2]=max(max(dp[1],arr[2]+arr[0]),arr[2]+arr[1]);
    /* for dp[3] intution heps in arriving at this recurrence relation */
    for(int i>=3;i<n;i++)
        dp[i] = max(max(arr[i]+dp[i-1],arr[i]+arr[i-1]+dp[i-3]),dp[i-1]);
    return dp[n];
}