#include <bits/stdc++.h>
using namespace std;
// class nqueen{
// public:
//     int n;
//     nqueen(int x){
//         n=x;
//     }
//     void solve(){
//         string s(n,'.');
//         vector<vector<string>> ans;
//         vector<string> arr(n);
//         for(int i=0;i<n;i++) arr[i]=s;
//         nt(0,arr,ans);
//         print(ans);
//     }
//     void print(vector<vector<string>>&ans){
//         if(ans.size()==0) cout<<"NP\n";
//         else{
//             for(auto i:ans){
//                 for(auto j:i){
//                     cout<<j<<endl;
//                 }
//                 cout<<"\n------\n";
//             }
//         }
//     }
//     bool valid(int row,int col,vector<string>arr){
//         int r=row,c=col;
//         while(r>=0 and c>=0){
//             if(arr[r][c]=='Q') return false;
//             r--;c--;
//         }
//         r=row,c=col;
//         while(r>=0 and c>=0){
//             if(arr[r][c]=='Q') return false;
//             c--;
//         }
//         r=row,c=col;
//         while(r<n and c>=0){
//             if(arr[r][c]=='Q') return false;
//             c--;r++;
//         }
//         return true;
//     }
//     void nt(int col,vector<string> arr,vector<vector<string>>&ans){
//         if(col==n){
//             ans.push_back(arr);
//             return;
//         }
//         for(int row=0;row<n;row++){
//             if(valid(row,col,arr)){
//                 arr[row][col]='Q';
//                 nt(col+1,arr,ans);
//                 arr[row][col]='.';
//             }
//         }
        
//     }
// };
class nqueen{
public:
    int n;
    vector<int> ld,rd,cl;
    nqueen(int n){
        this->n=n;
    }
    void print(vector<vector<int>>&ans){
        for(auto i:ans){
            for(auto j:i){
                if(j) cout<<"Q ";
                else cout<<"_ ";
            }cout<<endl;
        }
    }
    void solve(){
        vector<vector<int>> arr(n,vector<int>(n,0));
        ld.resize(2*n+1,0);
        rd.resize(2*n+1,0);
        cl.resize(n,0);
        if(get(0,arr)==false){
            cout<<"np";
        }
        else{
            print(arr);
        }
    }
    bool get(int col,vector<vector<int>>&arr){
        if(col==n)return true;
        for(int i=0;i<n;i++){
            if(ld[i+n-col-1]!=1 and rd[i+col]!=1 and cl[i]!=1){
                ld[i+n-col-1]=1;
                rd[i+col]=1;
                cl[i]=1;
                //imp
                arr[i][col]=1;
                if(get(col+1,arr)) return true;
                arr[i][col]=0;
                ld[i+n-col-1]=0;
                rd[i+col]=0;
                cl[i]=0;
            }
        }
        return false;
    }
};
int main()
{
    cout << "Enter the no of rows :" << endl;
    int n;cin >> n;
    nqueen q(n);
    q.solve();
    return 0;
}