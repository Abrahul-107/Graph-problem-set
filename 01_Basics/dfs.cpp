#include<iostream>
#include<vector>
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

    void startDfs(int startNode)
    {
        vector<int>visited(vertices,0);
        cout<<"Dfs traversal"<<" ";
        dfs(startNode,visited);
        cout<<endl;
    }

    void dfsDisconnected()
    {
        vector<int>visited(vertices,0);
        cout<<" dfs traversal : disconnected"<<endl;
    
        for(int i=0;i<vertices;++i)
        {
            if(!visited[i])
                dfs(i,visited);
            cout<<endl;
        }


    }

private:
    void dfs(int node, vector<int>&visited)
    {
        visited[node] = 1;
        cout<<node<<" ";
        for(auto neighbour: adjList[node])
        {
            if(!visited[neighbour])
                dfs(neighbour,visited);

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
    bool connected = 0;
    cout<<"this is connected or disconnected"<<endl;
    if(connected)
    {
         int startNode;
        cin>>startNode;
        g.startDfs(startNode);
        return;

    }

    //For disconnected graph
    g.dfsDisconnected();
    
    return 0;
}