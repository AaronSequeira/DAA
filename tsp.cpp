#include <iostream>
#include <vector>
#include<algorithm>
#include <climits>
using namespace std;

int PathCost(vector<vector<int>> graph, vector<int> tour){
    int n = graph.size();
    int cost=0;
    for(int i=0;i<n-1;i++){
        cost+= graph[tour[i]][tour[i+1]];
    }
    cost+= graph[tour.back()][tour[0]];
    return cost;
}

int TSP(vector<vector<int>> graph, int V){
    int minCost = INT_MAX;
    int currentCost;
    vector<int> minPath(V,0);
    vector<int> tour(V);
    for(int i=0;i<V;i++){
        tour[i] = i;
    }

    do{
        currentCost = PathCost(graph,tour);
        if(currentCost < minCost) {
            minCost = currentCost;
            minPath = tour;
        }

    }while(next_permutation(tour.begin()+1,tour.end()));

    return minCost;
}


int main(){
    vector<vector<int>> graph = {   {INT_MAX, 20, 30, 10, 11},
                                    {15, INT_MAX, 16, 4, 2},
                                    {3, 5, INT_MAX, 2, 4},
                                    {19, 6, 18, INT_MAX, 3},
                                    {16, 4, 7, 16, INT_MAX}};
    int V = graph.size();
    cout<<"Minimum path cost to travel back to the source: "<<TSP(graph, V);

    
    return 0;
}