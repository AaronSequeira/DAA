#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void CoinChangeDynamic(vector<int> coin, int n, int sum){
    vector<vector<int>> d(n, vector<int>(sum+1));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= sum; j++){
            if (j == 0){
                d[i][0] = 1;
            } 
            else if (coin[i] <= j){
                d[i][j] = d[i][j - coin[i]] + (i > 0 ? d[i-1][j] : 0);
            }
            else if(coin[i] > j)
                d[i][j] = (i > 0 ? d[i-1][j] : 0);
        }
    }
    //display
    cout<<"table:"<<endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= sum; j++) {
            cout << d[i][j] << " ";
        }
    cout << endl;
    }
    
    cout << "No of ways: " << d[n-1][sum];

}

int main(){
    int n, sum = 0;
    cout << "enter no of coin: ";
    cin >> n;
    vector<int> coin(n);
    cout << "enter coins: " << endl;;
    for (int i = 0; i < n; i++){
        cin >> coin[i];
    }
    cout << "enter sum: ";
    cin >> sum;
    CoinChangeDynamic(coin, n, sum);
    return 0;
}