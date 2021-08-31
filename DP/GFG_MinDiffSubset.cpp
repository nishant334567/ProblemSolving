/* ------------------------------- ----------- Minimum Subset Difference ---------------------------------------- 
Partition a set into two subsets such that the difference of subset sums is minimum

Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute
difference between their sums is minimum. If there is a set S with n elements, then if we assume 
Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2))
should be minimum.

Example: 

Input:  arr[] = {1, 6, 11, 5} 
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11  

*/

/* solution:
we have to select two subset sum such that their difference is minimum
first we will observe what all are the possible sum we could make out of it
then for these sum(1st) there is 2nd sum(2nd) = Total sum-sum(1st) 
out of all these differences return 
min of all(abs [sum(2nd)-sum(1st)] )*/

/* O(2^n) recursive solution */

/* O(n*sum) ---- DP*/


int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        int dp[n+1][(sum/2)+1];
        for(int i=0;i<=sum/2;i++)
            dp[0][i]=0;
        for(int i=0;i<=n;i++)
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
        int diff=INT_MAX;
        for(int i=sum/2;i>=0;i--)
        {
            if(dp[n][i]==1){
                diff = min(diff,abs(sum-2*i));
                break;
            }
            
        }
        return diff;
	} 