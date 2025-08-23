/*
Problem statement : you have given an array and untill your k will not become 0 you have to rotate it
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> rotate(vector<int> &nums , int k){
    //step 1 
    int n = nums.size();
    int rear = nums.size()-1; // rear will point at the last index of vector
    while(k != 0){
        int index = (rear+1)%n; //to go on circular way 
        nums[index] = nums[rear];
        k--; //decrement k 
    }
    return nums;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    int k = 3;
    vector<int> result = rotate(arr , k);

    for(auto val : result){
        cout << val << endl;
    }
}