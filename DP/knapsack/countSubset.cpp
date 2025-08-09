#include<bits/stdc++.h>
using namespace std;

int countSubset(vector<int>&arr, int sum){
    int n = arr.size();
    int W = sum;
    int t[n+1][W+1];

    //base condition :
    if(n == 0 && sum == 0){
        return 0;
    }

    //initialization : 
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(i == 0){
                t[i][j] = 0;
            }
            if(j==0){
                t[i][j] = 1;
            }
        }
    }
    //fill the middle values : 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] +
                                t[i-1][j]; //here why we did (+) because here we
                //we will check all the elements if we include 2 and then 3 and 5 the sum is 10 thats why
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][W];
}

int main(){
    vector<int>arr = {2,3,5,6,8,10};
    int sum = 10;

    int result = countSubset(arr, sum);
    cout << "no of subsets are in array is : " << result << endl;
}