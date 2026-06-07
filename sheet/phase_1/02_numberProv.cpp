class Solution {

private:
    void dfs(int startNode,vector<int>&visited,vector<vector<int>>&adjList)
    {
        visited[startNode]=1;
        for(auto neighbour:adjList[startNode])
        {
            if(!visited[neighbour])
                dfs(neighbour,visited,adjList);

        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        vector<vector<int>>adjList(n);

        for(int src=0;src<n;++src)
        {
            for(int dest=0;dest<n;++dest)
            {
                if(isConnected[src][dest]==1 && src!=dest)
                {
                    adjList[src].push_back(dest);
                    adjList[dest].push_back(src);
                }
            }
        }
        vector<int>visited(n,0);
        int count = 0 ;
        for(int startNode=0;startNode<n;++startNode)
        {
            if(!visited[startNode])
            {
                count++;
                dfs(startNode,visited,adjList);
            }
        }   
        return count;     
    }
     
};