/* You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. You have to find the longest chain which can be formed from the given set of pairs. 
 
Input:
N = 5
P[] = {5  24 , 39 60 , 15 28 , 27 40 , 50 90}
Output: 3

  */

 /* Intution is
    we know that p1 and p2 are only going to be a part of chain if 
    p1->first < p2->first
    therefore we sort the chain according to the first one
    then apply LIS on the array of chains
  */

int maxChainLen(struct val p[],int n)
{
//Your code here
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++)
        v[i]={p[i].first,p[i].second};
    sort(v.begin(),v.end());
    vector<int>dp(v.size(),1);
    int ans = 1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(v[i].first>v[j].second)
                dp[i]=max(dp[i],1+dp[j]);
            ans = max(ans,dp[i]);
        }
    }
    return ans;
}