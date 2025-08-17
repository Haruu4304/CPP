/*
Coin change problem 2 : here we are trying to get minimum no of coins 
to get the result - 
*/

#include<bits/stdc++.h>
using namespace std;

int coinChange(vector<int> &coin, int sum){
    int n = coin.size(); 
    int t[n+1][sum+1];
    //initialization : 
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(j==0){
                t[i][0] = 0;
            }
            if(i == 0){
                t[0][j] = INT_MAX-1;
            }
        }
    }

    //2nd row initialization - 
    int i = 1;
    for(int j=1; j<sum+1; j++){
        if(j%coin[0] == 0){ // 3/3 = 0
            t[i][j] = j/coin[0]; // 3/3 = 1 
        }else{
            t[i][j] = INT_MAX-1; // 4/ 3 = INT_MAX-1
        }
    }

    //now filling the middle terms - 
    for(int i=2; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(coin[i-1] <= j){
                t[i][j] = min(t[i][j-coin[i-1]] + 1 , t[i-1][j]);
            }else{
                t[i][j] = t[i-1][j]; //not including
            }
        }
    }

    if(t[n][sum] == INT_MAX-1){
        return -1;
    }else{
        return t[n][sum];
    }
}

int main(){
    vector<int> coin = {1};
    int sum = 0;
    cout << "minimum no of coins are required are : " << coinChange(coin , sum);
}