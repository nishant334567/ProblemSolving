/*  https://www.geeksforgeeks.org/partition-problem-dp-18/ */

/* --------------------------------------------------Equal Subset Problem--------------------------------------------- 
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.

*/

/* Solution 
    we have to divide into 2 sub arrays such that all elements are contained in totality in both arrays
    in that case we'll have sum of each subset as sum/2
    Hence the question now changes to whether it is possible to have a subset with sum =  sum/2
 */

class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        if(sum%2!=0)
            return 0;
        int dp[n+1][(sum/2)+1];
        for(int i=0;i<=sum/2;i++)
            dp[0][i]=0;
        for(int i=1;i<=n;i++)
            dp[i][0]=1;
        for(int i = 1;i<=n;i++)
        {
            for(int j=1;j<=sum/2;j++)
            {
                if(arr[i-1]<=j)
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum/2];
    }
};