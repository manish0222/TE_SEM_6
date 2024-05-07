#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define v 6

int mindist(int dist[], bool visit[])
{
    int mini=INT_MAX,minidx;
    for(int i=0;i<v;i++)
    {
      if(visit[i]==false && dist[i]<=mini)
      {
          mini=dist[i];
          minidx=i;
      }
    }
    return minidx;
}

void print(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < v; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

void dijkstra(int graph[v][v],int src)
{
    int dist[v];
    bool visit[v];

    for(int i=0;i<v;i++)
    {
        dist[i]=INT_MAX;
        visit[i]=false;
    }

    dist[src]=0;
    for(int c=0;c<v-1;c++)
    {
        int u=mindist(dist,visit);
        visit[u]=true;
        for(int i=0;i<v;i++)
        {
            if(!visit[i] && graph[u][i] && dist[u]!=INT_MAX && dist[u]+graph[u][i]<dist[i])
            {
                dist[i]=dist[u]+graph[u][i];
            }
        }
    }
    print(dist);
}
int main()
{
   int graph[v][v]= {
      {0, 1, 2, 0, 0, 0},
      {1, 0, 0, 5, 1, 0},
      {2, 0, 0, 2, 3, 0},
      {0, 5, 2, 0, 2, 2},
      {0, 1, 3, 2, 0, 1},
      {0, 0, 0, 2, 1, 0}
   };
    dijkstra(graph, 0);
    return 0;
}
