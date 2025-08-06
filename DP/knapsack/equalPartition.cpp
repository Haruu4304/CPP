/*
Equal sum partition - 
*/

#include<bits/stdc++.h>
using namespace std;

bool subSetSum(vector<int> &arr, int sum){
    int n = arr.size();
    int t[n+1][sum+1];

    //step 1 : initialization
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(i == 0){
                t[i][j] = false;
            }
            if(j == 0){
                t[i][j] = true;
            }
        }
    }

    //step 2 : now the fill the middle boxes - 
    for(int i=1; i<=n ; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1] <= j){
                t[i][j] = max(t[i-1][j-arr[i-1]] ,
                                t[n-1][j]);
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][sum];
}


bool EqualPartition(vector<int> &arr, int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }

    if(sum % 2 != 0){
        return false;
    }else if(sum % 2 == 0){
        return subSetSum(arr , sum/2);
    }
}

int main(){
    vector<int> arr = {1,5,3};
    int n = arr.size();

    bool result = EqualPartition(arr , n);

    cout << "Result of the array is : " << result << endl;
}