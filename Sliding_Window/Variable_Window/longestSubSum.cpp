/*
longest Subarray of sum k.
*/

#include<bits/stdc++.h>
using namespace std;

int LongestSubarraySum(vector<int> arr , int n , int k){
    int i=0,j=0;
    int sum = 0;
    int mx = INT_MIN;
    while(j<n){
        sum = sum + arr[j];
        //case I 
        if(sum < k){
            j++;
        }
        //case II
        else if(sum == k){
            mx = max(mx , j-i+1);
            j++;
        }
        //case III
        else if(sum > k){
            while(sum > k){
                sum = sum - arr[i];
            }
            i++;
            j++;
        }
    }
    return mx;
}

int main(){
    vector<int> arr;
    int n , k;
    int result = 0;
    cin >> n >> k;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        arr.push_back(x);
    }   
    result = LongestSubarraySum(arr , n , k);
    cout << "Longest subarray of sum is : " << result;
}