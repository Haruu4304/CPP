/*
now performing memorization on knapsack problem on a recursive order 
- 
here we are creating one (t) matrix - 
here we change only one thing that is - check before the recursive call where it is -1 or not
if yes then do the recursive call else take that value - 
*/

#include<bits/stdc++.h>
using namespace std;

int knapsackMemo(vector<int>&wt, vector<int>&val, int W, int n){
    //step 1 : base condition
    if(n==0 || W == 0){
        return 0;
    }

    int t[n+1][W+1];
    memset(t, -1 , sizeof(t));

    //step 2 : check before function call
    if(t[n][W] != -1){
        return t[n][W];
    }

    if(wt[n-1] <= W){
        return max(val[n-1] + knapsackMemo(wt, val , wt[n-1] - W , n-1) , 
                    kanpsackMemo(wt, val , W , n-1));
    }else if(wt[n-1] > W){
        return knapsackMemo(wt , val , W , n-1);
    }

}

int main(){
    vector<int> wt;
    vector<int> val;
    int W;
    int n;
    cin >> n >> W;
    for(int i=0; i<n; i++){
        cout << "enter for weight array :" << endl;
        int x;
        cin >> x;
        wt.push_back(x);
        cout << "enter for value array : " << endl;
        int y;
        cin >> y;
        val.push_back(y);
    }

    int maxProfit = knapsackMemo(wt, val , W , n);

    cout << "Max Profit of knapsack is : " << maxProfit;
}