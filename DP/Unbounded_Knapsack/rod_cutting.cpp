/*
Rod Cutting problem in Unbounded knapsack - 
*/
#include<bits/stdc++.h>
using namespace std;

int rodCuttingProblem(vector<int>&length, vector<int>&price, int N){
    int t[N+1][N+1];
    //initilization-
    for(int i=0; i<=N; i++){
        for(int j = 0; j <= N; j++){
            if(i == 0 || j == 0){
                t[i][j] = 0;
            }
        }
    }

    //fill the blanks values - 
    for(int i=1; i<=N; i++){
        for(int j = 1; j <= N; j++){
            if(length[i-1] <= j){
                t[i][j] = max(price[i-1] + t[i][j-length[i-1]] , 
                                t[i-1][j]);
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[N][N];
}

int main(){
    vector<int> length = {1,2,3,4,5,6,7,8};
    vector<int> price = {2,3,4,1,5,6,8,10};
    int N = length.size();
    
    cout << "Max Profit : " << rodCuttingProblem(length, price , N);
}