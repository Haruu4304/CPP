#include<bits/stdc++.h>
using namespace std;

int M = 1e9 + 7;

int numberOfWays(int n, int x) {
    //generate power array - 
    vector<int> powers;

    for(int base=1; pow(base,x) <= n; base++){
        //store the powers
        powers.push_back((int)pow(base, x));
    }

    int m = powers.size();
    vector<vector<int>> t(m + 1, vector<int>(n + 1, 0)); //created one t matrix 

    //initialization step 
    for(int i=0; i<=m; i++){
        t[i][0] = 1; //row to make 1
    }

    //filling the middle values - 
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(powers[i - 1] <= j) {
                t[i][j] = (t[i - 1][j - powers[i - 1]] + t[i - 1][j]) % M;
            } else {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[m][n];
}

int main(){
    cout << numberOfWays(10,2);
}