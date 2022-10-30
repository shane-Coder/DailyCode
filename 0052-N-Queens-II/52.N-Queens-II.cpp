/*The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.
Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
Input: n = 1
Output: 1*/
class Solution {
private:
    int count;
public:
    bool CheckValid(vector<string>&board,int row,int col){
        //check column
        for(int i=row;i>=0;i--){
            if(board[i][col]=='Q')
                return false;
        }
        //check left diagonal
        for(int i=row,j=col;i>=0&&j>=0;i--,j--){
            if(board[i][j]=='Q')
                return false;
        }
        for(int i=row,j=col;i>=0&&j<board.size();i--,j++){
            if(board[i][j]=='Q')
                return false;
        }
        return true;
    }
    void backtrack(vector<string>&board,int row){
        if(row==board.size()){
            count++;
            return;
        }
        else{
            for(int col=0;col<board.size();col++){
                if(CheckValid(board,row,col)){
                    board[row][col]='Q';
                    backtrack(board,row+1);
                    board[row][col]='.';
                }
            }
        }
    }
    int totalNQueens(int n) {
        count=0;
        vector<string>board(n,string(n,'.'));
        backtrack(board,0);
        return count;
    }
};