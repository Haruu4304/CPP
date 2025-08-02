/*
Pascal Triangle - 
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int n){
    vector<vector<int>> result(n);
    for(int i=0; i<n; ++i){
        result[i] = vector<int>(i+1, 1);
        for(int j=1; j<i; ++j){
            result[i][j] = result[i-1][j] + result[i-1][j-1];
        }
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> result;
    result = generate(n);
    for(const auto &row : result){
        for(int val : row){
            cout << val << " ";
        }
        cout << endl;
    }
}