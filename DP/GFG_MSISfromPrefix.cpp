/* Maximum sum increasing subsequence from a prefix and a given element after prefix is must 
Link : https://www.geeksforgeeks.org/maximum-sum-increasing-subsequence-from-a-prefix-and-a-given-element-after-prefix-is-must/  */

int maxSumIS(int arr[], int n)  
	{  
    int ans = arr[0];
	int lis[n];

    for(int i = 0 ;i<n; i++)
        lis[i]=arr[i];
    for(int i = 1;i<n;i++)
    {
        if(a[i]>=a[k])
            continue; 
        /* SINCE LAST A[K] will be the last value of increasing sunseq */
        for(int j = 0;j<i;j++)
        {
            if(arr[j]<arr[i])
                lis[i] = max(lis[i],lis[j]+arr[i]);
            ans = max(ans,lis[i]);
        }
    }
    return ans;
	}

    int new_