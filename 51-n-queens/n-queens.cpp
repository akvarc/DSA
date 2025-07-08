class Solution {
public:
    /*bool isSafe(int row,int col,vector<string> &board,int n){
        int duprow=row;
        int dupcol=col;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            col--;
            row--;
        }
        col=dupcol;
        row=duprow;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        col=dupcol;
        row=duprow;
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;

    }
public:
    void solve(vector<vector<string>>&ans,vector<string> &board,int col,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(i,col,board,n)){
                board[i][col]='Q';
                solve(ans,board,col+1,n);
                board[i][col]='.';
            }
        }

    }*/
    void solve(int col,vector<string>&board,int n,vector<vector<string>>&ans,vector<int>&leftrow,vector<int>&lowerdiagonal,
    vector<int>&upperdiagonal){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(leftrow[i]==0 && lowerdiagonal[i+col]==0 && upperdiagonal[n-1+col-i]==0 ){
                leftrow[i]=1;
                lowerdiagonal[i+col]=1;
                upperdiagonal[n-1+col-i]=1;
                board[i][col]='Q';
                solve(col+1,board,n,ans,leftrow,lowerdiagonal,upperdiagonal);
                leftrow[i]=0;
                lowerdiagonal[i+col]=0;
                upperdiagonal[n-1+col-i]=0;
                board[i][col]='.';
            }

        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector <int> leftrow(n,0), lowerdiagonal(2*n-1,0),upperdiagonal(2*n-1,0);
        solve(0,board,n,ans,leftrow,lowerdiagonal,upperdiagonal);
        return ans;
    }
};