#include <bits/stdc++.h>
using namespace std;
class nqueen{
    // Time Complexity: O(N!)
// Auxiliary Space: O(N2)
public:
    int n;
    nqueen(int n){
        this->n=n;
    }
    bool valid(int row,int col,vector<string> &arr,int n){
        int r=row,c=col;
        while(r>=0 and c>=0){
            if(arr[r][c]=='Q') return false;
            r--;c--;
        }
        c=col;
        r=row;
        while(c>=0){
            if(arr[r][c]=='Q') return false;
            c--;
        }
        c=col;r=row;
        while(r<n and col>=0){
            if(arr[r][c]=='Q') return false;
            r++;c--;
        }
        return true;
    }
    void get(int col,vector<string> &arr,vector<vector<string>>&ans,int n){
        if(col==n){
            ans.push_back(arr);
            return;
        }
        for(int row=0;row<n;row++){
            if(valid(row,col,arr,n)){
                arr[row][col]='Q';
                get(col+1,arr,ans,n);
                arr[row][col]='.';
            }
        }
    }
    vector<vector<string>> solve(int n){
        string s(n,'.');
        vector<vector<string>> ans;
        vector<string> arr(n);
        for(int i=0;i<n;i++) arr[i]=s;
        get(0,arr,ans,n);
        return ans;
    }
};
int main() {
    nqueen obj(2);
    auto k=obj.solve(5);
    if(k.size()==0) cout<<"NP";
    else cout<<k.size()<<endl;
    for(auto i:k){
        for(auto j:i){
            cout<<j<<endl;
        }
        cout<<"\n------\n";
    }

    return 0;
}

/*                 
                                                   Branch  and  bound  code                                   
                                                    Time Complexity: O(N!) 
                                                    Auxiliary Space: O(N)
#include <iostream>
#include <vector>
using namespace std;

vector<int> ld, rd, cl;

void print(const vector<vector<int>>& arr) {
    for (const auto& row : arr) {
        for (int cell : row) {
            if (cell)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

bool solveNQueens(vector<vector<int>>& arr, int n, int col) {
    if (col >= n)
        return true;

    for (int i = 0; i < n; i++) {
        if (ld[i + n - col - 1] != 1 && rd[i + col] != 1 && cl[i] != 1) {
            cl[i] = 1;
            ld[i + n - col - 1] = rd[i + col] = 1;
            arr[i][col] = 1;

            if (solveNQueens(arr, n, col + 1))
                return true;

            arr[i][col] = 0; // Backtrack
            cl[i] = 0;
            ld[i + n - col - 1] = rd[i + col] = 0;
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n, 0)); // Initialize the board with zeros

    ld.resize(2 * n - 1);
    rd.resize(2 * n - 1);
    cl.resize(n);

    if (!solveNQueens(arr, n, 0)) {
        cout << "No solution exists for " << n << " queens." << endl;
    } else {
        cout << "Solution for " << n << " queens:" << endl;
        print(arr);
    }

    return 0;
}
*/