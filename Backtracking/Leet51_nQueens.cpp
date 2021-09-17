/* 
https://leetcode.com/problems/n-queens/    51. N-Queens

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
 */

class Solution {
public:
    vector<vector<string>>fin_sol;
    bool isSafe(vector<vector<char>>sol,int row,int col)
    {
        int i=row;
        int j=col;
        while(i>=0 && j>=0)
        {
            if(sol[i][j]=='Q')
                return false;
            i--;
            j--;
        }
        i=row,j=col;
        while(i<=sol.size()-1 && j>=0)
        {
            if(sol[i][j]=='Q')
                return false;
            i++;
            j--;
        }
        i=row,j=col;
        while(j>=0)
        {
            if(sol[i][j]=='Q')
                return false;
            j--;
        }
        return true;
    }
    void util(int col,vector<vector<char>>sol,int n)
    {
        if(col==n)
        {
            vector<string>s;
            for(int i=0;i<sol.size();i++)
            {
                string t(sol[i].begin(),sol[i].end());
                s.push_back(t);
            }
            fin_sol.push_back(s);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(isSafe(sol,i,col))
            {
                sol[i][col]='Q';
                util(col+1,sol,n);
            }
            sol[i][col]='.';
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>>sol(n,vector<char>(n,'.'));
        util(0,sol,n);
        return fin_sol;
    }
};