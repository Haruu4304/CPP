/*
Problem statement : 
we have to return the count of subset who having the same diff -
diff = sum(s1) - sum(s2);
let's solve this - 
*/

#include<bits/stdc++.h>
using namespace std;

int countSubset(vector<int>&arr , int sum){
    int n= arr.size();
    int t[n+1][sum+1];

    //base condition
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

    //filling the result
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
    return t[n][sum];
}

int countSubsetDiff(vector<int>&arr , int diff){
    int range = 0;
    for(int i=0; i<arr.size(); i++){
        range+=arr[i];
    }
    if(diff > range) return 0;
    if ((range + diff) % 2 != 0) return 0;
    int sum = (diff + range) / 2; // finding the value of s1

    return countSubset(arr , sum); //matching it with already solved problem
}

int main(){
    vector<int> arr = {1,1,2,3};
    int diff = 1;
    int count = countSubsetDiff(arr , diff);
    cout << "the count of subset having the same difference is : " << count << endl;
}