/*
Minimum subarray of sum of k;
*/

#include<bits/stdc++.h>
using namespace std;

int MinSubSum(vector<int>arr , int size , int target){
    int i=0, j=0;
    int sum = 0;
    int mn = INT_MAX;
    while(j < size){
        //calculation 
        sum += arr[j];
        //case I
        if(sum < target){
            j++;
        }
        //case II
        else if(sum == target){
            mn = min(mn , j-i+1);
            j++;
        }
        //case III
        else if(sum > target){
            while(sum > target){
                mn = min(mn , j-i+1);
                sum -=arr[i];
                i++;
            }
            if(sum == target){
                mn = min(mn , j-i+1);
            }
            j++;
        }
    }
    return (mn == INT_MAX) ? 0 : mn;
}

int main(){
    vector<int> arr;
    int target , n;
    cin >> target >> n;
    cout << "enter the elements of an array : " << endl;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int result = MinSubSum(arr , n , target);
    cout << "Minimum Subaary sum of k is : " << result;
}