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

    //Adding edge to the list , where each pointer will take one list tc : O(1) and sc:O(V+E)
    void addEdge(int source,int dest)
    {
        adjList[source].push_back(dest);
        adjList[dest].push_back(source);
    }

    void printList()
    {
        for(int i=0;i<vertices;++i)
        {
            cout<< i << " --> ";
            for(auto neighbour:adjList[i])
                cout<<neighbour<<" ";
            cout<<endl;

        }
    }

};

int main()
{
    Graph g(4);

    cout << "Initial empty adjacency list:\n";
    g.printList();

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);

    cout<<"Adeded edge to the list " <<endl;
    g.printList();


    return 0;

}