#include <iostream>
#include <algorithm>

using namespace std;

struct Item {
    int p; 
    int w; 
    float pw; 
};

bool compare(Item a, Item b) {
    return a.pw > b.pw; 
}

float knapsack(Item items[], int cap, int n) {
    sort(items, items + n, compare); // descending profit
    float total_profit = 0.0f;

    for(int i=0;i<n;i++){
        if(cap >= items[i].w){
            total_profit += items[i].p;
            cap -= items[i].w;
        }
        else if(cap < items[i].w && cap > 0){
            total_profit += float(items[i].p*(cap/float(items[i].w)));
            cap=0;
        } 
    }

    return total_profit;
}

int main() {
    Item items[] = {{100, 20, 0}, {60, 10, 0}, {120, 30, 0}};
    int cap = 50;
    int n = sizeof(items) / sizeof(items[0]);

    for (int i = 0; i < n; i++) {
        items[i].pw = (float) items[i].p / items[i].w;
    }

    float profit = knapsack(items, cap, n);
    cout << "Profit: " << profit << endl;
    return 0;
}