/* Variation  LIS */
int maxSumIS(int arr[], int n)  
	{  
    int ans = arr[0];
	int lis[n],lds[n];
    lis[0] = arr[0];

    for(int i = 0 ;i<n; i++)
        lis[i]=arr[i];
    for(int i = 1;i<n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            if(arr[j]<arr[i])
                lis[i] = max(lis[i],lis[j]+arr[i]);
            ans = max(ans,lis[i]);
        }
    }
    return ans;
	} 