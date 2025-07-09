class Solution {
public:
    bool issafe(int i ,int j,vector<vector<int>>&grid,vector<vector<int>>&board,int n){
         if(i>=0 && j>=0 && i<n && j<n && board[i][j]==-1 ){
            return true;
         }
         return false;
    }
    bool knightutil(int s,int j, int step,int n, vector<vector<int>>&grid, vector<vector<int>>& board,vector<int>&dx,vector<int>&dy){
        if(step==n*n){
            return true;
        }
        for(int i=0;i<8;i++){
            int sj=dx[i]+s;
            int js=dy[i]+j;
            if(issafe(sj,js,grid,board,n) && grid[sj][js] == step){
                board[sj][js]=step;
                if(knightutil(sj,js,step+1,n,grid,board,dx,dy)){
                    return true;
                }
                board[sj][js]=-1;
            }
        }
        return false;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> dx = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};
     vector<vector<int>> board(n, vector<int>(n, -1));
    board[0][0]=0;
    
    bool f= knightutil(0,0,1,n ,grid,board,dx,dy);
    return f;
    }
};