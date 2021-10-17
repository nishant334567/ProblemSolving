/* Very beautiful question
Multisource BFS */

struct Node{
    int x,y,time;
    Node(int _x,int _y,int _z)
    {
        x = _x;
        y = _y;
        time = _z;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int oranges = 0;
        queue<Node>q;
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col ;j++)
            {
                if(grid[i][j]==2)
                    q.push(Node(i,j,0));
                if(grid[i][j]!=0)
                    oranges++;
            }
        }
        int ansTime=0;
        int rotten = 0;
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        while(!q.empty())
        {
            Node temp = q.front();
            q.pop();
            ansTime = temp.time;
            rotten++;
            for(int i = 0 ; i<4 ; i++)
            {
                int newX = temp.x+dx[i];
                int newY = temp.y+dy[i];
                int newTime = temp.time+1;
                if(newX>=0 && newY>=0 && newY<col && newX<row && grid[newX][newY]==1)
                {
                    q.push(Node(newX,newY,newTime));
                    grid[newX][newY]=2;
                }
            }
            
        }
        if(rotten == oranges)
            return ansTime;
        return -1;
    }
};