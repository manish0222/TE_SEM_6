// C++ program to print DFS traversal from
// a given vertex in a given graph
#include <bits/stdc++.h>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph {
public:
	map<int, bool> visited;
	map<int, list<int> > adj;

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
    	list<int>::iterator i;
    	for (i = adj[v].begin(); i != adj[v].end(); ++i)
    		if (!visited[*i])
    			DFS(*i);
    }
};

class Graph_bfs {
 
    // No. of vertices
    int V;
 
    // Pointer to an array containing adjacency lists
    vector<list<int> > adj;
 
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
        list<int> queue;
     
        // Mark the current node as visited and enqueue it
        visited[s] = true;
        queue.push_back(s);
     
        while (!queue.empty()) {
     
            // Dequeue a vertex from queue and print it
            s = queue.front();
            cout << s << " ";
            queue.pop_front();
     
            // Get all adjacent vertices of the dequeued
            // vertex s.
            // If an adjacent has not been visited,
            // then mark it visited and enqueue it
            for (auto adjacent : adj[s]) {
                if (!visited[adjacent]) {
                    visited[adjacent] = true;
                    queue.push_back(adjacent);
                }
            }
        }
    }
};
// Driver code
int main()
{
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

