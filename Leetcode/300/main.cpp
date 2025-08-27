/*
Longest Increasing Subsequence - 
*/

#include<bits/stdc++.h>
using namespace std;

int LCS(vector<int>&arr , vector<int>&arr2 , int m , int n){
    //matrix- 
    vector<vector<int>> t(m+1 , vector<int>(n+1 , 0));

    //now fill the matrix - 
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(arr[i-1] == arr2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }else{
                t[i][j] = max(t[i][j-1] , t[i-1][j]);
            }
        }
    }

    return t[m][n];
}

int longestIncreasingSubsquence(vector<int> &arr){
    //step 1 : sort it
    vector<int> arr2 = arr;
    sort(arr2.begin() , arr2.end());

    //step 2 : remove duplicates - 
    auto it = unique(arr2.begin() , arr2.end());
    arr2.erase(it , arr2.end());

    //now apply LCS method - 
    int m = arr.size();
    int n = arr2.size();
    int result = LCS(arr , arr2 , m , n);

    return result;
}

int main(){
    vector<int> arr = {10 , 9 , 2 , 5 ,3 , 7 , 101 , 18};

    cout << longestIncreasingSubsquence(arr);
}