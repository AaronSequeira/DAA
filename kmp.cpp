#include <iostream>
#include <vector>

using namespace std;

void computeLPS(string pattern, vector<int> &lps, int n){
    int i = 1;
    int l = 0;
    lps[0] = 0;
    while(i < n){
        if(pattern[i] == pattern[l]){
            l++;
            lps[i] = l;
            i++;
        }
        else{
            if(l!=0){
                l = lps[l-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string text, string pattern){
    int m = text.length();
    int n = pattern.length();
    vector<int> lps(n);
    computeLPS(pattern, lps, n);

    int i=0,j=0;
    while(i<m){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }
        if(j==n){
            cout<<"Found the pattern at: "<<i-j<<endl;
            j = lps[j-1];
        }
        else if(i<m && text[i]!=pattern[j]){
            if(j!=0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }
}

int main(){
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    
    KMPSearch(text, pattern);
    
    return 0;
}