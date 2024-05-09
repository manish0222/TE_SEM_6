#include <bits/stdc++.h>
#include <climits>
using namespace std;
                                  //single source shortest pth 5th 2nd
class vertex{
public:
    int id,dist;
    vertex(int i,int d){
        id=i;dist=d;
    }
};
class Comp{
public:
bool operator()(const vertex&b,const vertex&c){
    return b.dist>c.dist;
}
};
class Graph{
public:
    vector<vector<pair<int,int>>> graph;
    vector<int> distance,prev;
    vector<bool> visit;
    int src;
    Graph(vector<vector<pair<int,int>>> g,int s){
        src=s;
        graph=g;
    }
    void solve(){
        int n=graph.size();
        distance.resize(n,INT32_MAX);
        prev.resize(n,-1);
        visit.resize(n,false);
        priority_queue<vertex,vector<vertex>,Comp> p;
        p.push(vertex(src,0));
        distance[src]=0;
        while(p.empty()==false){
            vertex u=p.top();p.pop();
            if(visit[u.id]) continue;
            visit[u.id]=1;
            for(auto adj:graph[u.id]){
                int v=adj.first;
                int wt=adj.second;
                if(distance[v]>wt+distance[u.id]){
                    distance[v]=wt+distance[u.id];
                    prev[v]=u.id;
                    p.push(vertex(v,distance[v]));
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<src<<" to "<<i<<"  :: ";
            if(distance[i]==INT32_MAX){
                cout<<"NP\n";
            }
            else{
                cout<<src<<"->";
                stack<int> st;
                int curr=i;
                while(curr!=src){
                    st.push(curr);
                    curr=prev[curr];
                }
                
                while(st.empty()==false){
                    cout<<st.top()<<"->";
                    st.pop();
                }
                cout<<" Dist "<<distance[i]<<endl;
            }
        }
    }
};
int main() {
    cout<<"enter n ";
    int n;cin>>n;
    vector<vector<pair<int,int>>> v;
    for(int i=0;i<n;i++) v.push_back({});
    cout<<"Enter edges\n";
    while(true){
        // cout<<" enter ";
        int x,y,t;cin>>x>>y>>t;
        if(x<0 || y<0 or t<0) break;
        v[x].push_back({y,t});
        v[y].push_back({x,t});
        // cout<<"done ";
    }
    Graph g(v,0);
    g.solve();
    return 0;
}
/*
0 1 4
0 7 8
1 7 11
7 6 1
7 8 7
1 2 8
2 8 2
8 6 6
6 5 2
2 5 4
2 3 7
3 5 14
3 4 9
5 4 10
-1 -1 -1
*/



/*
0 1 4
0 2 1
1 3 2
2 1 3
2 3 5
-1 -2 -1
*/
