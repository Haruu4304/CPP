/*
This problem is related to coin change problem 1 - where we are finding the maximum ways of numbers where
the sum is equal

*/

#include<bits/stdc++.h>
using namespace std;

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    int t[n+1][amount+1];
    
    //initialization - 
    for(int i=0; i<=n; i++){
        for(int j=0; j<=amount; j++){
            if(i == 0){
                t[0][j] = 0;
            }if(j == 0){
                t[i][0] = 1;
            }
        }
    }

    //now fill the middle values - 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=amount; j++){
            if(coins[i-1] <= j){
                t[i][j] = t[i][j-coins[i-1]] + t[i-1][j];
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][amount];
}

int main(){
    vector<int> coins = {1,2,3};
    int sum = 5;
    cout << " The result : " << change(sum , coins);
}