#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int mindist(vector<int> edgeWt, vector<int> Q, int V){
    int minDist = INT_MAX, minIndex;
    for(int i=0;i<V;i++){
        if(Q[i] == 1 && edgeWt[i] < minDist)
        {
            minDist = edgeWt[i];
            minIndex=i;
        }
    }
    return minIndex;
}

void prims(vector<vector<int>> graph, int V){
    vector<int> edgeWt(V);
    vector<int> Q(V);
    vector<int> parent(V);

    int u;

    for(int i=0;i<V;i++){    //initializing all the vertices
        edgeWt[i] = INT_MAX;
        Q[i] = 1;          // 1 means the vertice is unvisited
        parent[i] = -1;
    }
    edgeWt[0] = 0; // first vertice will have 0 dist

    for(int i=0;i<V-1;i++){
        u = mindist(edgeWt,Q,V); // find the next vertice which is unvisited and has the minimum distance
        Q[u]=0;
        for(int v=0;v<V;v++){
            if(Q[v] == 1 && graph[u][v] && graph[u][v] < edgeWt[v]){
                edgeWt[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int total_wt = 0;
    //display
    for(int i=1;i<V;i++){
        cout<<i<<" - "<<parent[i]<<"\tedge: "<<graph[i][parent[i]]<<endl;
        total_wt += graph[i][parent[i]];
    }
    cout<<"Total weight of MST: "<<total_wt;
}

int main(){
    
    vector<vector<int>> graph = {{0,2,0,6,0},
                                 {2,0,3,8,5},
                                 {0,3,0,0,7},
                                 {6,8,0,0,9},
                                 {0,5,7,9,0}};
    int V = 5; // no of vertices
    prims(graph,V);
    return 0;
}