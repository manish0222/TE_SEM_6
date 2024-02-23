// refer this    https://www.youtube.com/watch?v=wuVwUK25Rfc
/* problem link  
https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
*/
#include <bits/stdc++.h>
using namespace std;
bool safeColor(int col,int node,int color[],int graph[101][101],int n){
    //col is colour 
    // node is the node and color denotes color
    for(int ind=0;ind<n;ind++){
        if(ind!=node and graph[ind][node]==1 and color[ind]==col) return false;
    }
    return true;
}
bool solve(int node,int color[],int graph[101][101],int m,int n){
    if(node==n) return true;
    for(int i=1;i<=m;i++){
        if(safeColor(i,node,color,graph,n)){
            color[node]=i;
            if(solve(node+1,color,graph,m,n)) return true;
            color[node]=0;
        }
    }   
    return false;
}
int main() {
    //  ** NOTE USED BIRECTIONAL GRAPH AND BACTRACKING **
                //Test Case 1
    // int n=4,m=3,e=5;//nodes , colours,edges
    // int edges[e][2] = {{0,1},{1,2},{2,3},{3,0},{0,2}};
                //Test Case 2
    int n=3,m=2,e=3;
    int edges[e][2] = {{0,1},{1,2},{0,2}};
    
    int arr[101][101]={0};  //can also declare of n*n
    int color[n]={0};
    for(int i=0;i<e;i++){
        int x=edges[i][0];
        int y=edges[i][1];
        arr[x][y]=1;
        arr[y][x]=1;
    }
    if(solve(0,color,arr,m,n)){
         cout<<"YES\n";
         for(int i=0;i<n;i++){
             cout<<i<<"->"<<color[i]<<endl;
         }
    }
    else cout<<"NO\n";
    return 0;
}
