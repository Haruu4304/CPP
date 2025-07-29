/*
Problem statement: Given an array of integers and a window size k, find the maximum value in each sliding 
window of size k.
*/

#include<bits/stdc++.h>
using namespace std;

int MaxSumSubarray(vector<int> &v, int size, int k){
    int i= 0 , j = 0;
    int sum = 0;
    int maxSum = INT_MIN;

    while(j < size){
        sum = sum + v[j];
        if(j-i+1 < k){
            j++;
        }else if(j-i+ 1 == k){
            maxSum = max(maxSum, sum);
            sum = sum - v[i];
            i++;
            j++;
        }
    }

    return maxSum;
}


int main(){
    vector<int> v;
    int n , k , result;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    result = MaxSumSubarray(v, n , k);
    cout << "Maximum value in each sliding window of size " << k << " is: " << result << endl;
    return 0;
}