/*
Problem Statement - 
Sequence Pattern mattching - 
we have given 2 string a and b where we have to return true when a is subsequence of b then only
else false;

return type -> Boolean
*/

#include<bits/stdc++.h>
using namespace std;

int LCS(string s , string b , int m , int n){
    vector<vector<int>> t(m+1 , vector<int>(n+1 , 0));

    // Fill DP table
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s[i-1] == b[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }

    return t[m][n];
}

bool isSubsequence(string &s , string &t){
    int m = s.size();
    int n = t.size();
    int LCSResult = LCS(s , t , m , n);

    if(m == LCSResult){
        return true;
    }else{
        return false;
    }
}

int main(){
    string s = "";
    string t = "";

    cout << isSubsequence(s , t);
}