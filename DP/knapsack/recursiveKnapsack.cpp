/*
Recursive knapsack problem - 
*/
#include<bits/stdc++.h>
using namespace std;

int knapsackRecursion(vector<int> &wt, vector<int> &val, int W, int n){
    //base condition
    if(n==0 || W == 0){
        return 0;
    }

    //choice diagram based call - 
    if(wt[n-1] <= W){
        return max(val[n-1] + knapsackRecursion(wt, val , wt[n-1] - W , n-1) , 
                    knapsackRecursion(wt, val , W , n-1));
    }else if(wt[n-1] > W){
        return knapsackRecursion(wt , val , W , n-1);
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

    int maxProfit = knapsackRecursion(wt, val , W , n);

    cout << "Max Profit of knapsack is : " << maxProfit;
}