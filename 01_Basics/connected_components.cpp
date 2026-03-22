//https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1
#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector<int>&visited,vector<int>&components,vector<vector<int>>&adjList)
{
    visited[node] = true;
    components.push_back(node);

    for(auto neighbour:adjList[node])
    {
        if(!visited[neighbour])
            dfs(neighbour,visited,components,adjList);
        
    }


}

vector<vector<int>> connectedComponets(int vertices,vector<vector<int>>&edges)
{
    vector<vector<int>>adjList(vertices);
    vector<int>visited(vertices,false);

    //Building adjList from edges
    for(auto edge:edges)
    {
        int src = edge[0];
        int dest = edge[1];
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);

    }

    vector<vector<int>>result;

    for(int i=0;i<vertices;++i)
    {
        if(!visited[i])
        {
            vector<int>component;
            dfs(i,visited,component,adjList);
            result.push_back(component);
            
        }
    }
    return result;
}


int main()
{
   int vertices = 7;

    vector<vector<int>> edges = {
    {0, 1},
    {1, 2},
    {3, 4},
    {5, 6}
};
    vector<vector<int>>res = connectedComponets(vertices,edges);
    for(auto list:res)
    {
        for(auto it:list)
            cout<<it<<" ";

        cout<<endl;
    }        
    


    return 0;
}