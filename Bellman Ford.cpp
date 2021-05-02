#include<iostream>
#include<vector>

using namespace std;
class Graph
{
public:
    int V;
    vector<int> *adj;
    vector<int> *weight;
    vector<int> visited;
    vector<int> not_visited;
    int* distance;

    int* parent;
    Graph(int vertices);
    void addEdge(int v1, int v2, int w);
    void dijkstra(int s);
    void bellman_ford(int s);
};

Graph::Graph(int vertices)
{
    V = vertices;
    adj = new vector<int>[vertices];
    weight = new vector<int>[vertices];

    for(int i=0; i<vertices; i++)
    {
        not_visited.push_back(i);
    }

    distance = new int[vertices];
    parent = new int[vertices];

    for(int i=0; i<vertices; i++)
    {
        distance[i] = 99999;
        parent[i] = -1;
    }
}

void Graph::addEdge(int v1, int v2, int w)
{
    adj[v1].push_back(v2);
    weight[v1].push_back(w);
}

/*void Graph::dijkstra(int src)
{
    while(!not_visited.empty())
    {
        int minnum = 999, index=-1;
        for(int i = 0; i<not_visited.size(); i++)
        {
            if(minnum>distance[not_visited.at(i)])
            {
                minnum = distance[not_visited.at(i)];
                index = i;
            }

        }
        int not_visited_item = not_visited.at(index);

        for(int i =index; i< not_visited.size()-1;i++)
        {
            not_visited[i] = not_visited[i+1];

        }
        not_visited.pop_back();

        for(int i = 0; i<adj[not_visited_item].size(); i++)
        {
            int v = adj[not_visited_item].at(i);
            distance[v] = distance[not_visited_item]+ weight[not_visited_item].at(i);
            parent[v] = not_visited_item;
        }

    }
}*/


void Graph::bellman_ford(int s)
{
    int k=1;

    while(k < V)
    {
        int i=0;
        while(i < V)
        {
            for(int j=0; j<adj[i].size(); j++)
            {
                if(distance[adj[i].at(j)] > distance[i]+weight[i].at(j))
                {
                    distance[adj[i].at(j)] = distance[i]+weight[i].at(j);
                    parent[adj[i].at(j)] = i;
                }
            }
            i++;
        }
        k++;
    }


}

int main()
{
    Graph g(4);

    g.addEdge(0,2,3);
    g.addEdge(0,1,5);
    g.addEdge(2,1,1);
    g.addEdge(1,3,2);


    int src =0;

    g.distance[src] = 0;
        g.bellman_ford(src);
         cout<<"distance:"<<g.distance[3];
         int V=3;

          cout<<"\nShortest Path\n";
    for(int i=V-1; i>=0; i--)
    {
        cout<<g.parent[i]<<" -> ";
    }


}
