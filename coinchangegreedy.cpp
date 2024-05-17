#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;


void CoinChangeGreedy(vector<int> &den, int n, int sum){
    int t;

    for(int i=0;i<n;i++){
        for (int j=0;j<n-i-1;j++){
            if(den[j]<den[j+1]){
                t = den[j];
                den[j]=den[j+1];
                den[j+1]=t;
            }
        }
    }

    for(int i=0;i<n;i++){
        while(sum>=den[i]){
            sum -= den[i];
            cout<<den[i]<<" , ";
        }
    }
}

int main(){
    int n,sum = 0;
    vector<int> den(n);
    cout<<"enter no of denominations: ";
    cin>> n;
    cout<<"enter denominations: "<<endl;;
    for (int i=0;i<n;i++){
        cin>> den[i];
    }
    cout<<"enter sum: ";
    cin>> sum;
    CoinChangeGreedy(den,n,sum);

    
    return 0;
}