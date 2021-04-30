#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
class Graph
{
public:
    int V;
    vector<int> *adj;
    vector<int> *weight;
    vector<int> not_visited;
    int *distance;
    //parent
    int *parent;
    Graph(int V);
    void addEdge(int v1, int v2, int w);
    void dijkstra(int src);

};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int>[V];
    //update weight size
    weight = new vector<int>[V];
    //add all vertex in not_visited
    for(int i = 0; i< V; i++)
    {
        not_visited.push_back(i);
    }

    //define size of distance and parent
    distance = new int[V];
    parent = new int[V];
    //initialize these arrays
    for(int i = 0; i< V; i++)
    {
        distance[i] = 99999999;
        parent[i] = -1;
    }
}

void Graph::addEdge(int v1, int v2, int w)
{
    adj[v1].push_back(v2);
    //update weight[v1]
    weight[v1].push_back(w);
}

//implement dijkstra(int src)
//while(!not_visited.emnpty())
void Graph::dijkstra(int src)
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
}



int main()
{
    Graph g(4);
    g.addEdge(0, 1,5);
    g.addEdge(0, 2,3);
    g.addEdge(2, 1,1);
    g.addEdge(1, 3, 2);

    int src = 0;
    g.distance[src] = 0;
    //call dijkstra to test shortest path
   // g.dijkstra(src);
   g.bellman_ford[src]
       cout<<"Distance: "<<g.distance[3]<<endl;
    int v = 3;
    cout<<"Path: ";
    while (v!=-1)
    {
        cout<<v<<" <-"<<' ';
        v = g.parent[v];
    }
}
