#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max(int a, int b){
    return (a>b?a:b);
}

int LeastCommonSubsequence(string a, string b){
    int l = 0;
    int m = a.length();
    int n = b.length();

   vector<vector<int>> LCS ((n+1) , vector<int>(m+1));
    
    for(int i = 0; i <=n; i++){
        for(int j = 0;j<=m;j++){
            if(i==0 || j==0){
                LCS[i][j] = 0;
            }
            else{
                LCS[i][j] = (b[i-1] == a[j-1]) ? (1 + LCS[i-1][j-1]) : max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
    }

    return LCS[n][m];
}

int main(){
    
    string a = "stone";
    string b = "one";
    cout<<"Length of the subsequence: \n"<<LeastCommonSubsequence(a,b);
    return 0;
}