#include <bits/stdc++.h>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph {
public:
	map<int, bool> visited;
	map<int, vector<int> > adj;

	// Function to add an edge to graph
	void addEdge(int v, int w)
    {
    	// Add w to v’s list.
    	adj[v].push_back(w);
    }

	// DFS traversal of the vertices
	// reachable from v
	void DFS(int v)
    {
    	// Mark the current node as visited and
    	// print it
    	visited[v] = true;
    	cout << v << " ";
    
    	// Recur for all the vertices adjacent
    	// to this vertex
    	// list<int>::iterator i;
    	for (auto i : adj[v])
    		if (!visited[i])
    			DFS(i);
    }
};

class Graph_bfs {
 
    // No. of vertices
    int V;
 
    // Pointer to an array containing adjacency lists
    vector<vector<int> > adj;
 
public:
    // Constructor
    Graph_bfs(int V)
    {
        this->V = V;
        adj.resize(V);
    }
 
    // Function to add an edge to graph
    void addEdge(int v, int w)
    {
        // Add w to v’s list.
        adj[v].push_back(w);
    }
    // Prints BFS traversal from a given source s
    void BFS(int s)
    {
        // Mark all the vertices as not visited
        vector<bool> visited;
        visited.resize(V, false);
     
        // Create a queue for BFS
        queue<int> queue;
     
        // Mark the current node as visited and enqueue it
        visited[s] = true;
        queue.push(s);
     
        while (!queue.empty()) {
     
            // Dequeue a vertex from queue and print it
            s = queue.front();
            cout << s << " ";
            queue.pop();
     
            // Get all adjacent vertices of the dequeued
            // vertex s.
            // If an adjacent has not been visited,
            // then mark it visited and enqueue it
            for (auto adjacent : adj[s]) {
                if (!visited[adjacent]) {
                    visited[adjacent] = true;
                    queue.push(adjacent);
                }
            }
        }
    }
};

class sol
{
public:
    bool measuredfs(int jug1, int jug2, int target)
    {
        unordered_set<int> seen;
        return dfs(0, jug1, jug2, target, seen);
    }

    bool dfs(int total, int jug1, int jug2, int target, unordered_set<int> &seen)
    {
        if (total == target)
        {
            return true;
        }
        if (seen.count(total) != 0 || total < 0 || total > jug1 + jug2)
        {
            return false;
        }
        cout << "Current total :" << total << endl;
        seen.insert(total);

        return dfs(total + jug1, jug1, jug2, target, seen) || 
        dfs(total - jug1, jug1, jug2, target, seen) || 
        dfs(total + jug2, jug1, jug2, target, seen) || 
        dfs(total - jug2, jug1, jug2, target, seen);
    }

    bool bfs(int jug1,int jug2,int target)
    {
        queue<int> q;
        unordered_set<int> seen;
        vector<int> step={jug1,-jug1,jug2,-jug2};
        q.push(0);
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            for(int s:step)
            {
               int tot=curr+s;
               if(tot==target)
               {
                 return true;
               }
               if(seen.count(tot)==0 && tot>=0 && tot<=jug1+jug2)
               {
                 seen.insert(tot);
                 q.push(tot);
               }
            }
        }
        return false;
    }
};
int main()
{
    sol s;
    int jug1,jug2,target;
    cout<<"Enter Jug1 Capacity :"<<endl;
    cin>>jug1;
    cout<<"Enter Jug2 Capacity :"<<endl;
    cin>>jug2;
    cout<<"Enter Target Capacity :"<<endl;
    cin>>target;
    if(s.measuredfs(jug1,jug2,target))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }

    if(s.bfs(jug1,jug2,target))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }


    
        // code for undirected graph
	//              DFS
	Graph g;
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Depth First Traversal"
			" (starting from vertex 2) \n";
	// Function call
	g.DFS(2);
    
    
        //BFS
    Graph_bfs g1(4);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(2, 0);
    g1.addEdge(2, 3);
    g1.addEdge(3, 3);
 
    cout << "\nFollowing is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g1.BFS(2);
    return 0;
}


