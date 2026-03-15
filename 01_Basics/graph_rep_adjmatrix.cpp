#include<iostream>
#include<vector>
using namespace std;

class Graph
{
    int vertices;
    vector<vector<int>> adjMatrix;

public:
    Graph(int v)
    {
        vertices = v;
        adjMatrix.resize(vertices,vector<int>(vertices,0));
    }

    //Adding edge to the adjececny matrix tc: O(1) sc: O(V*V)
    void addEdge(int src,int dest)
    {
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1; // For undirected graph
    }

    void printMatrix()
    {
        cout<<"Printing adjecency list"<<endl;
        for(int i=0;i<vertices;++i)
        {
            for(int j=0;j<vertices;++j)
            {
                cout<<adjMatrix[i][j]<< " ";
            }
            cout<<endl;
        }
    }

};

int main()
{
    Graph graph(4);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,3);

    graph.printMatrix();

    return 0;
}   