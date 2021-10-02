class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool comp(Item a,Item b)
    {
        if((a.value/(double)a.weight)>(b.value/(double)b.weight)) return true;
        return false;
    }
    double fractionalKnapsack(int w, Item arr[], int n)
    {

        double ans = 0;
        sort(arr,arr+n,comp);
        for(int i=0;i<n;i++)
        {
            if(w>0)
            {
                if(arr[i].weight<=w)
                {
                    ans+=arr[i].value;
                    w=w-arr[i].weight;
                    
                }
                else{
                    ans+=(w/(double)arr[i].weight)*((double)arr[i].value);
                    w=0;
                    break;
                }
                
            }
            else break;
        }
        return ans;
    }
        
};