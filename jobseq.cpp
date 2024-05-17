#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job{
    int JobNo;
    int deadline;
    int profit;
};

bool compare(Job a, Job b){
    return a.profit > b.profit;
}

void JobSequencing(Job arr[], int n){
    Job t;
    vector<bool> slot(n , false);
    vector<Job> result(n);

    for(int i=0; i<n;i++){
        slot[i] = false; // initiaizing all slots
    }

    sort(arr, arr + n, compare); // descending profit

    for(int i = 0; i<n; i++){
        for(int j = min(n, arr[i].deadline)-1; j>=0; j--){
            if(slot[j] == false){
                slot[j] = true;
                result[j] = arr[i];
                break;
            }
        }
    }

    for(int i =0; i<n; i++){
        if(slot[i] == true)
        {
            cout<<" --> ";
            cout<<"Job "<<result[i].JobNo;
        }
    }

}  

int main(){
    
    int n=5;
    Job arr[] = {{ 1, 2, 100},
                 { 2, 1, 19 },
                 { 3, 2, 27 },
                 { 4, 1, 25 },
                 { 5, 3, 15 }};
    JobSequencing(arr,n);
    
    return 0;
}