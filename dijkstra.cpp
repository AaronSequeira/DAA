#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int mindist(vector<int> dist, vector<int> Q, int V){
    int minDist = INT_MAX, minIndex;
    for(int i=0;i<V;i++){
        if(Q[i] == 1 && dist[i] < minDist)
        {
            minDist = dist[i];
            minIndex=i;
        }
    }
    return minIndex;
}

void dijkstra(vector<vector<int>> graph, int V, int src){
    vector<int> dist(V);
    vector<int> Q(V);
    int u;

    for(int i=0;i<V;i++){    //initializing all the vertices
        dist[i] = INT_MAX;
        Q[i] = 1;            // 1 means the vertice is unvisited
    }
    dist[src] = 0;

    for(int i=0;i<V-1;i++){
        u = mindist(dist,Q,V); // find the next vertice which is unvisited and has the minimum distance
        Q[u]=0;
        for(int v=0;v<V;v++){
            if(Q[v] == 1 && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v] < dist[v]){
                dist[v] = dist[u]+graph[u][v];
            }
        }
    }

    //display
    for(int i=0;i<V;i++){
        cout<<"vertex "<<i+1<<" distance: "<<dist[i]<<endl;
    }
}

int main(){
    
    vector<vector<int>> graph = {{0,2,4,0,0,0},
                                 {2,0,1,7,0,0},
                                 {4,1,0,0,3,0},
                                 {0,7,0,0,2,1},
                                 {0,0,3,2,0,5},
                                 {0,0,0,1,5,0}};
    int V = 6; // no of vertices
    int src = 0; //src vertex
    dijkstra(graph,V,src);
    return 0;
}

