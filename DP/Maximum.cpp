/* GFG : Wrong Editorial try (FAILS) test case 1 2 3 3 5 4 4
CODEFORCES : https://codeforces.com/contest/455/problem/A
 */

/* 
Alex doesn't like boredom. That's why whenever he gets bored, he comes up with games. One long winter evening he came up with a game and decided to play it.

Given a sequence a consisting of n integers. The player can make several steps. In a single step he can choose an element of the sequence (let's denote it ak) and delete it, at that all elements equal to ak + 1 and ak - 1 also must be deleted from the sequence. That step brings ak points to the player.

Alex is a perfectionist, so he decided to get as many points as possible. Help him. */

/* input
9
1 2 1 3 2 2 2 2 3

output
10 */

/* 
explanation
intuition says start taking maximum value 
but this fails for 1 2 3 3 4, for the solution given in gfg

lets make a frequency array : 
1 ----> 1
2 ----> 1
3 ----> 2
4 ----> 1

for maximum sum, you have to ensure that you pick maximum (but their is a catch)
you cant take two maximum simultaneously because of problem constraint
i.e if you pick 4 you have to delete all 3's
Remaining array --> 1 2          ---> ans = 4
Pick 2          --> Empty        ---> ans = 4 + 2 = 6 
(If you pick 2 delete all occurence of 1 & 3, if they are there)

what is we pick don't pick 4 or we can say we picked 3
then delete all occurences of 2 and 4
Remaining array --> 1 3          ---> ans = 3
Pick 3          --> 1            ---> ans = 6
(If you pick 3 delete all occurence of 2 & 4, if they are there)
Pick 1          --> Empty  ---> ans = 7

Reason for this is you cant take two maximum simultaneously because of problem constraint
i.e Choosing max_value will add (max_value * frequency(max_value)) to answer
    but we'll loose (max_value-1 * frequency(max_value-1));
    
    And if we choose max_value-1, we'll add (max_value-1 * frequency(max_value-1)) to ans 
    ans we'll loose (max_value * frequency(max_value))

    From above case if we take 4*1 i.e (max_value * frequency(max_value))
    we'll loose 3*2 and remaining ans will be answer from part 1 2 
    i.e ans = 4*1 + f([1 2])

    Or if we take 3 we'll have ans = 3*2 + f([1]) 
    because we'll loose all occurence of 2 & 4

    We have to decide which is a better deal
    i.e You have to thing along the line of maximum but choose wisely whether to consider it or loose it


 */

void solve()
{
    int n;
    cin>>n;
    int maxi = -1;
    vector<ll>a(100002,0);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a[x]++;
        maxi=max(maxi,x);
    }
    vector<ll>b(100002,0);
    b[0]=0;
    b[1]=a[1];
    for(ll i=2;i<=100000;i++)
    {
        b[i]=max(b[i-1],(a[i]*i)+b[i-2]);
    }
    cout<<b[maxi];

}