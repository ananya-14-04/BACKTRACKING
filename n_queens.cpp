class Solution {
public:
    void solve(int col,vector<int>&rowwise,vector<int>&upperdiagonal,vector<int>&lowerdiagonal,vector<vector<string>>&ans,vector<string>&board,int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return ;
        }
        
        for(int row=0;row<n;row++)
        {
            if(rowwise[row]==0 && upperdiagonal[n-1+col-row]==0 && lowerdiagonal[col+row]==0)
            {
                board[row][col]='Q';
                rowwise[row]=1;
                upperdiagonal[n-1+col-row]=1;
                lowerdiagonal[col+row]=1;
                solve(col+1,rowwise,upperdiagonal,lowerdiagonal,ans,board,n);
                board[row][col]='.';
                rowwise[row]=0;
                upperdiagonal[n-1+col-row]=0;
                lowerdiagonal[col+row]=0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        vector<int>rowwise(n,0);
        vector<int>lowerdiagonal(2*n-1,0);
        vector<int>upperdiagonal(2*n-1,0);
        
        solve(0,rowwise,upperdiagonal,lowerdiagonal,ans,board,n);
        return ans;
    }
};