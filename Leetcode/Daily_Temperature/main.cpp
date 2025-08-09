/*
Daily temperature
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int> &arr){
    int n = arr.size();
    //here we will check if the ith element is lesser than next then that is warmth temp
    int i = 0;
    int j = i+1;
    int count = 0;
    vector<int> result;
    while(i < n){
        if(arr[i] < arr[j]){ //agar greater element mila toh
            count++;
            result.push_back(count);
            count = 0;
            i++;
            j = i+1;
        }else if(arr[i] > arr[j]){ //if we didn't find any then we will simple check their next element 
            count++;
            j++;
        }else if(i == n-1){ // if no next element is greater then - 
            result.push_back(0);
        }else{
            result.push_back(0);
        }
    }
    return result;
}

int main(){
    vector<int> arr = {73,74,75,71,69,72,76,73};
    vector<int> result = dailyTemperatures(arr);

    for(auto &val : result){
        cout << val << " ";
    }
}