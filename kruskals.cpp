#include<iostream>
#include<climits>
#include <vector>
using namespace std;
int V ;
vector<int> parent;

int find(int i){
    while(parent[i] != i){
        i = parent[i];
    }
    return i;
}

void union_set(int i, int j){
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}


int main(){
     vector<vector<int>> graph = {
                                    {INT_MAX, 1, 7, INT_MAX, INT_MAX},
                                    {1, INT_MAX, 5, 4, 3},
                                    {7, 5, INT_MAX, INT_MAX, 6},
                                    {INT_MAX, 4, INT_MAX, INT_MAX, 2},
                                    {INT_MAX, 3, 6, 2, INT_MAX}};
    V = graph.size();
    parent.resize(V);
    int mincost=0;

    for(int i =0; i<V;i++){ // initializing parent
        parent[i] = i;
    }

    int edgecount=0;
    while(edgecount<V-1){
        int min = INT_MAX;
        int a = -1;
        int b = -1;
        for(int i = 0; i<V;i++){
            for(int j =0; j<V; j++){
                if(find(i) != find(j) && graph[i][j]<min){    // finding the smallest edge weight
                    a = i;
                    b = j;
                    min = graph[i][j];
                }
            }
        }
        union_set(a,b);
        edgecount += 1;
        mincost += min;
        cout<<"Edge "<<a<<" - "<<b<< "\tCost: "<<min<<endl;
    }
    return 0;
}