/*
now we will try the top - down approach  - 
ke issee hum log kaise try kare karneka 
here we convert all the recursive calls into iterative
and it assumed that it is widely used to give a better apporach 

let's see -
*/
#include<bits/stdc++.h>
using namespace std;
//gloablly declare the t matrix : 
int t[100][1002];

int top_down(vector<int>& wt, vector<int>&val, int W , int n){
    //we are doing 0th row of vertical and 0th column make - 0;
    //converting base condition of recursion to iterative way - 
    for(int i=0; i<=n; i++){
        for(int j=0; j<=W; j++){
            if(i==0 || j==0){
                t[i][j] = 0;
            }
        }
    }

    //now make iterative the choice diagram - 
    //now we all created that 0 now we will start from 1 index 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            if(wt[i-1] <= j){
                t[i][j] = max(val[i-1] + t[i-1][j - wt[i-1]] , 
                                        t[i-1][j]);
            }else{
                t[i][j]= t[i-1][j];
            }
        }
    }
    return t[n][W];
}

int main(){
    vector<int> wt = {2,3,4,5,6};
    vector<int> val = {10,30,5,3,23};
    int W = 45;
    int n = 5;
    // memset(t, -1 , sizeof(t)); //put -1 to all the block of matrix
    int Profit = top_down(wt, val , W, n);
    cout << "Max Profit is : " << Profit;
}