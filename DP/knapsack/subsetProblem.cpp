/*
Subset of Sum : 
it is related to knapsack only 
*/

#include<bits/stdc++.h>
using namespace std;


bool subSetSum(vector<int>&arr, int n , int sum){
    int t[n+1][sum+1];

    //step 1 : initilization - 
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(i == 0){
                t[i][j] = false;
            }
            if(j==0){
                t[i][j] = true;
            }
        }
    }

    //step 2 : fill the empty boxes now 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            //case I : if my arr element is lesser then sum then :
            if(arr[i-1] <= j){
                t[i][j] = max(t[i-1][j-arr[i-1]] , 
                                t[i-1][j]);
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][sum];
}

int main(){
    vector<int>arr = {2,3,7,8,10};
    int n = arr.size();
    int sum = 14;
    bool result = subSetSum(arr , n , sum);
    cout << "Result of true or false : " << result << endl;
}