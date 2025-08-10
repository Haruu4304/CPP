/*
this problem is pretty simple
where we are trying to get the minimum subsest Sum difference
it is very much realtated to equal sum partition
soo let's dive - 

time complexity - O(n*sum(arr))
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> subsetSum(vector<int> &arr , int sum){
    int n= arr.size();
    bool t[n+1][sum+1];
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

    //now fill the middle part - 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1] <= j){
                t[i][j] = max(t[i-1][j-arr[i-1]] , t[i-1][j]);
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    //now insert the last row of t matrix only half for our s1 
    vector<int> result;
    for (int j = 0; j <= sum/2; j++) { // only half
        if (t[n][j]) { //if and only if it is true
            result.push_back(j);
        }
    }
   return result; 
}

int minimumSubsetSumDiff(vector<int> &arr){
    int range = 0;
    int n = arr.size();
    for(int i=0; i<n; i++){
        range += arr[i];
    }
    //step 1:
    vector<int> result = subsetSum(arr , range);

    //step 2: now i am calculating the minimum
    int mn = INT_MAX;
    for(int i=0; i<result.size(); i++){
        mn = min(mn , abs(range - 2*result[i]));
    }
    //step 3: now retunr the mini
    return mn;
}

int main(){
    vector<int> arr = {1,2,7};
    int result = minimumSubsetSumDiff(arr);
    cout << "minimum difference of subset sum is : " << result << endl;
}