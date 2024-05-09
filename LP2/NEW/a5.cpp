#include <iostream>
#include <bits/stdc++.h>
#include <climits>
//                                        SINGLE SOURCE SORTEST PTH
using namespace std;

class Vertex {
public:
    int id;
    int distance;
    
    Vertex(int _id, int _distance) {
        id = _id;
        distance = _distance;
    }
};

class CompareVertices {
public:
    bool operator()(const Vertex& a, const Vertex& b) {
        return a.distance > b.distance;
    }
};

class Dijkstra {
private:
    vector<vector<pair<int, int>>> graph;
    vector<int> dist;
    vector<int> prev;
    vector<bool> visited;
    int source;
public:
    Dijkstra(const vector<vector<pair<int, int>>>& _graph, int _source) {
        graph = _graph;
        source = _source;
    }

    void shortestPaths() {
        int n = graph.size();
        dist.resize(n, INT32_MAX);
        prev.resize(n, -1);
        visited.resize(n, false);

        priority_queue<Vertex, vector<Vertex>, CompareVertices> pq;

        dist[source] = 0;//imp
        pq.push(Vertex(source, 0));

        while (!pq.empty()) {
            Vertex u = pq.top();
            pq.pop();

            if (visited[u.id])
                continue;

            visited[u.id] = true;
            for (auto neighbour : graph[u.id]) {
                int v = neighbour.first;
                int weight = neighbour.second;

                if (dist[v] > dist[u.id] + weight) {
                    dist[v] = dist[u.id] + weight;
                    prev[v] = u.id;//imp
                    pq.push(Vertex(v, dist[v]));//imp
                }
            }
        }

        cout << "Shortest paths from vertex " << source << "\n";
        for (int i = 0; i < n; i++) {
            cout << "Vertex " << i << ": ";
            if (dist[i] == INT32_MAX) {
                cout << "No path";
            }
            else {
                stack<int> path;
                int current = i;
                while (current != source) {
                    path.push(current);
                    current = prev[current];
                }
                cout << source;
                while (!path.empty()) {
                    cout << " --> " << path.top();
                    path.pop();
                }
                cout << " (Distance : " << dist[i] << ")";
            }
            cout << endl;
        }
    }
};

int main() {

    vector<vector<pair<int, int>>> graph = {
        {{1, 4}, {2, 1}}, // Edge: (0, 1) with weight 4, Edge: (0, 2) with weight 1
        {{3, 2}}, // Edge: (1, 3) with weight 2
        {{1, 3}, {3, 5}}, // Edge: (2, 1) with weight 3, Edge: (2, 3) with weight 5
        {} // No outgoing edges from vertex 3
    };

    Dijkstra dijkstra(graph, 1);
    dijkstra.shortestPaths();

    return 0;
}
/*
#include <iostream>
#include <bits/stdc++.h>
#include <climits>
using namespace std;
class vertex{
public:
    int id, dist;
    vertex(int i,int d){
        id=i;
        dist=d;
    }
};
class compV{
public:
    bool operator()(const vertex&a,const vertex&b){
        return a.dist>b.dist;
    }
};
class Graph{
public:
    vector<vector<pair<int,int>>> graph;
    vector<int> distance,prev;
    vector<bool> visit;
    int src;
    Graph(vector<vector<pair<int,int>>>&g,int s){
        graph=g;
        src=s;
    }
    void calcDist(){
        int n=graph.size();
        for(int i=0;i<n;i++){
            cout<<i<<" : ";
            if(distance[i]==INT32_MAX) cout<<"DNE \n";
            else{
                stack<int> st;
                int curr=i;
                while(curr!=src){
                    st.push(curr);
                    curr=prev[curr];
                }
                cout<<"Src "<<src<<" ";
                while(!st.empty()){
                    cout<<st.top()<<" ";
                    st.pop();
                }
                cout<<" distance "<<distance[i]<<endl;
            }
        }
    }
    void dikstra(){
        int n=graph.size();
        distance.resize(n,INT32_MAX);
        prev.resize(n,-1);
        visit.resize(n,false);
        priority_queue<vertex,vector<vertex>, compV> pq;
        pq.push(vertex(src,0));
        distance[src]=0;
        while(!pq.empty()){
            vertex u=pq.top();pq.pop();
            if(visit[u.id]) continue;
            
            visit[u.id]=true;
            for(auto adjnode:graph[u.id]){
                int v=adjnode.first;
                int wt=adjnode.second;
                
                if(distance[v]>distance[u.id]+wt){
                    distance[v]=wt+distance[u.id];
                    prev[v]=u.id;
                    pq.push(vertex(v,distance[v]));
                }
            }
        }
        
        
        calcDist();
    }
};
int main()
{
    vector<vector<pair<int, int>>> graph = {
        {{1, 4}, {2, 1}}, // Edge: (0, 1) with weight 4, Edge: (0, 2) with weight 1
        {{3, 2}}, // Edge: (1, 3) with weight 2
        {{1, 3}, {3, 5}}, // Edge: (2, 1) with weight 3, Edge: (2, 3) with weight 5
        {} // No outgoing edges from vertex 3
    };
    Graph g(graph,1);
    g.dikstra();

    return 0;
}

*/