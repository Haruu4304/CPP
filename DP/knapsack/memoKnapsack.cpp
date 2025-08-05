/*
now performing memorization on knapsack problem on a recursive order 
- 
here we are creating one (t) matrix - 
here we change only one thing that is - check before the recursive call where it is -1 or not
if yes then do the recursive call else take that value - 
*/

#include<bits/stdc++.h>
using namespace std;

int t[100][1002];

int memoKnapsack(vector<int> wt, vector<int> val, int W, int n){
    //step 1 : create one matrix named as : t

    //step 2 : base condition -
    if(n==0 || W == 0){
        return 0;
    }

    //step 3 : check before checking the condition of recursion - 
    if(t[n][W] != -1){
        return t[n][W];
    }

    //else we will check the recursive condition
    if(wt[n-1] <= W){
        return t[n][W] = max(val[n-1] + memoKnapsack(wt, val , W-wt[n-1], n-1) ,
                            memoKnapsack(wt, val , W , n-1));
    }
    else if(wt[n-1] > W){
        return t[n][W] = memoKnapsack(wt, val , W , n-1);
    }
}

int main(){
    vector<int> wt = {2,3,4,5,6};
    vector<int> val = {10,30,5,3,23};
    int W = 45;
    int n = 5;
    memset(t, -1 , sizeof(t)); //put -1 to all the block of matrix
    int Profit = memoKnapsack(wt, val , W, n);
    cout << "Max Profit is : " << Profit;
}