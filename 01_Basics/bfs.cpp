#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Graph
{
    int vertices;
    vector<vector<int>>adjList;

public:
    Graph(int v)
    {
        vertices = v;
        adjList.resize(vertices);
    }
    void addEdge(int source,int dest)
    {
        adjList[source].push_back(dest);
        adjList[dest].push_back(source);
    }

    void bfs(int startNode)
    {
        cout<<"BFS traversal: "<<endl;

        queue<int>q;
        q.push(startNode);
        vector<int>visited(vertices,0);
        visited[startNode] = 1;


        while(!q.empty())
        {
            int current = q.front();
            q.pop();
            cout<<current<<" ";
            for(int neighbour:adjList[current])
            {
                if(!visited[neighbour])
                {
                    visited[neighbour] = 1;
                    q.push(neighbour);
                }
            }

        }

        
    }


};




int main()
{
    int vertices,edge;
    cin>>vertices>>edge;

    Graph g(vertices);
    while(edge--)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u,v);
    }
    int start;
    cin>>start;
    g.bfs(start);
    
    
    return 0;
}