
#include<iostream>
#include<vector>

using namespace std;

class graph
{
public:
    int v;
    bool *visited;
    int *color;
    vector<int> *adj;
    graph(int vertices);
    void addEdge(int v1, int v2);
    void DFS(int s);
};

graph::graph(int vertices)
{
    v=vertices;
    adj = new vector<int>[vertices];
    visited = new bool[vertices];
    for(int i = 0; i< vertices; i++) visited[i] = false;
    color = new int[vertices];
    for(int i = 0; i< vertices; i++) color[i] = 1;
}

void graph::addEdge(int v1, int v2)
{
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);

}

void graph::DFS(int s)
{
    visited[s] = true;
    for(int i = 0; i<adj[s].size(); i++)
    {
        int v = adj[s].at(i);
        if(!visited[v])
        {
            if(color[s]== 1)color[v] =2;
            else color[v] = 1;
            DFS(v);
        }
    }
}

int main()
{
    graph g(4);


    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(1,3);
    for(int  i = 0; i <g.v; i++)
    {
        if(!g.visited[i])
        {
            g.DFS(i);
        }
    }

    for(int  i = 0; i <g.v; i++)
    {

        for(int j = 0; j < g.adj[i].size(); j++)
        {
            int x = g.adj[i].at(j);
            if(g.color[i]==g.color[x])
            {
                cout<<"Not Bicolorable"<<endl;
                return 0;
            }
        }
    }
    cout<<"Bicolorable"<<endl;
}
