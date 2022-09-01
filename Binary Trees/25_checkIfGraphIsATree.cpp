#include <bits/stdc++.h>
using namespace std;

class Graph{

    int V;                                                      // number of vertices
    int E;                                                     // number of edges
    list <int> *adj;                                          // pointer to an array for adjacency list
        
    void dfsTraversal(int v, bool visited[], int parent);

public:
    Graph(int V);                                               // Constructor
    void addEdge(int v, int w);                                // to add an edge to the graph
    bool isConnected();                                       // returns true if graph is connected
    bool isTree();                                           // returns true if graph is tree
};

Graph::Graph(int V){
    
    E = 0;
    this -> V = V;
    adj = new list <int>[V];
}

void Graph :: addEdge(int v, int w){

    E++;                                                     // increase the number of edges
    adj[v].push_back(w);                                    // Add w to v's list
    adj[w].push_back(v);                                   // Add v to w's list
}

void Graph :: dfsTraversal(int v, bool visited[], int parent){

    visited[v] = true;                                  // Mark the current node as visited
    list <int>::iterator i;

    for(i = adj[v].begin(); i != adj[v].end(); ++i){        // Recur for all vertices adjacent to this vertex
        if(!visited[*i])                // if an adjacent is not visited, then recur for that adjacent
            dfsTraversal(*i, visited, v);
    }
}

bool Graph :: isConnected(){
    // marks all vertices that are not visited and part of recursion stack
    bool *visited = new bool[V];

    for(int i = 0; i < V; i++)
        visited[i] = false;

    dfsTraversal(0, visited, -1);   // performing dfs traversal in graph and marking reachable vertices from 0 to true.

    for(int u = 0; u < V; u++){     
        if(!visited[u])             // if we find any vertices which is not reachable from 0
            return false;           // then we return false since graph is not connected.
    }

    return true;                    // since all nodes were reachable so we returned true & hence the graph is connected
}

bool Graph :: isTree(){
    
    return isConnected() and E == V-1; // if the graph is connected and has V-1 edges, then it is a tree. i.e., E = V-1.
}


// Driver program to test above functions
int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isTree()? cout << "Graph is Tree\n":
                 cout << "Graph is not Tree\n";
 
    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.isTree()? cout << "Graph is Tree\n":
                 cout << "Graph is not Tree\n";
 
    return 0;
}
