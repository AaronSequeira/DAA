#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int MatrixChainMult(vector<int>dim, int i, int j){
    int minCost = INT_MAX;
    int cost;
    if(i == j)
        return 0;
    else{
        for(int k = i; k < j; k++){
            cost = MatrixChainMult(dim, i, k) + MatrixChainMult(dim, k+1, j) + dim[i-1]*dim[k]*dim[j];
            if(cost < minCost){
                minCost = cost;
            }
        }
        
        return minCost;
        
    }
}

int main(){
    vector<int> dim = {3, 2, 4, 2, 5};
    int n = dim.size() - 1; 
    vector<vector<int>> d(n, vector<int>(n)); 
    


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j >= i){
                d[i][j] = MatrixChainMult(dim, i+1, j+1);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << d[i][j] << "\t";
        } 
        cout << endl;
    }

    cout << "Minimum number of ways of multiplying: " << d[0][n-1] << endl;
    return 0;
}
