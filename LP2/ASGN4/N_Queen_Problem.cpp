#include <bits/stdc++.h>
using namespace std;
class Solution {
    bool valid(int col,int row,vector<string> &board,int n){
        int tcol=col,trow=row;
        while(col>= 0 && row>=0){
            if(board[row][col]=='Q'){return false;}
            row--;
            col--;
        }
        col=tcol;
        row=trow;
        while(col>=0){
            if(board[row][col]=='Q'){return false;}
            col--;
        }
        col=tcol;
        row=trow;
        while(row<n && col>=0){
            if(board[row][col]=='Q'){return false;}
            col--;
            row++;
        }
        // cout<<trow<<" "<<tcol<<endl;
        return true;

    }
    void solve(int col,vector<vector<string>> &ans,vector<string> &board,int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(valid(col,row,board,n)==true){
                board[row][col]='Q';
                solve(col+1,ans,board,n);
                board[row][col]='.';
            }
        }

    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> board(n);
        for(int i=0;i<n;i++){board[i]=s;}
        solve(0,ans,board,n);
        return ans;
    }
};
int main(){
    Solution* obj=new Solution();
    auto k=obj->solveNQueens(4);
    for(auto i:k){
        for(auto j:i){
            cout<<j<<endl;
        }
        cout<<"\n----  ----\n";
    }
}
