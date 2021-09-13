int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int inc = arr[0];
        int exc = 0;
        
        for(int i = 1;i<n;i++)
        {
            int temp=exc;
            exc = max(exc,inc);
            inc = temp + arr[i];
        }
        return max(exc,inc);
    }