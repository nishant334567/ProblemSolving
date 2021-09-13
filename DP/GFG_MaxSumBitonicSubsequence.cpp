/* SIMILAR TO MAXIMUM LENGTH BITONIC */
int maxSumBS(int *arr , int n )
{
    int lis[n],lds[n];
    lis[0] = arr[0];
    lds[n-1] = arr[n-1];

    for(int i = 0 ;i<n; i++)
    {
        lis[i]=arr[i];
        lds[i]=arr[i];
    }
    for(int i = 1;i<n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            if(arr[j]<arr[i])
                lis[i] = max(lis[i],lis[j]+arr[i]);
        }
    }
    
    for(int i = n-2;i>=0;i--)
    {
        for(int j = n-1;j>i;j--)
        {
            if(arr[j]<arr[i])
                lds[i] = max(lds[i],lds[j]+arr[i]);
        }
    }
    int ans = INT_MIN;
    for(int i = 0 ;i<n; i++)
        ans = max(ans,lds[i]+lis[i]-arr[i]);
    return ans;
}
