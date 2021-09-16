// https://www.geeksforgeeks.org/path-maximum-average-value/

/* Given a square matrix of size N*N, where each cell is associated with a 
specific cost. A path is defined as a specific sequence of cells which starts
 from the top-left cell move only right or down and ends on bottom right cell.
  We want to find a path with the maximum average over all existing paths. Average 
  is computed as total cost divided by the number of cells visited in the path. */

for all i, 1 <= i <= N
   dp[i][0] = dp[i-1][0] + cost[i][0];    
for all j, 1 <= j <= N
   dp[0][j] = dp[0][j-1] + cost[0][j];            
otherwise    
   dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + cost[i][j]; 

/* finall divide by 2*n-1 to find average */