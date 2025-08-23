/*
i'm doing - 
Longest Common Substring
    Substring -> Continuous Manner
*/

#include<bits/stdc++.h>
using namespace std;

int LCS(string x , string y, int n , int m){
    vector<vector<int>> t(n+1 , vector<int>(m+1 , 0)); 
    int ans = 0;

    //fil the middle values - 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(x[i-1] == y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
                ans = max(ans  , t[i][j]);
            }else{
                t[i][j] = 0;
            }
        }
    }

    return ans;
}

int main(){
    string x = "abcde";
    string y = "abfce";

    int n = x.size();
    int m = y.size();

    cout << "Result :" << LCS(x , y , n , m);
}