#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        vector<bool> visited(n, false);
        vector<vector<int>> graph(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        stack<int> st;
        st.push(source);
        visited[source] = true;

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (node == destination)
                return true;

            for (int neighbour : graph[node]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    st.push(neighbour);
                }
            }
        }

        return false;
    }
};

int main() {
    int n = 6;

    vector<vector<int>> edges = {
        {0,1},
        {0,2},
        {3,5},
        {5,4},
        {4,3}
    };

    int source = 0;
    int destination = 5;

    Solution sol;

    bool ans = sol.validPath(n, edges, source, destination);

    cout << (ans ? "true" : "false") << endl;

    return 0;
}