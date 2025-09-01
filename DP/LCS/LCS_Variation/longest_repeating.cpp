/*
Problem Statement - 
Longest Repeating Subsequence - 
*/

#include<bits/stdc++.h>
using namespace std;

int LongestRepeatingSubsequence(string &s){
    string b = s;
    int m = s.size();
    int n = b.size();
    vector<vector<int>> t(m+1 , vector<int>(n+1 , 0));

    // Fill DP table
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s[i-1] == b[j-1] && i!=j){
                t[i][j] = 1 + t[i-1][j-1];
            }else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }

    return t[m][n];
}

int main(){
    string s = "aabebcdd";
    cout << LongestRepeatingSubsequence(s);
}