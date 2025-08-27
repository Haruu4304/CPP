/*
Longest Palindrome Subsequence - 
*/

#include<bits/stdc++.h>
using namespace std;

int LCS(string s , string b , int m , int n){
    vector<vector<int>> t (m+1 , vector<int>(n+1 , 0)); //matrix 

    //initilization
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i == 0 || j == 0){
                t[m][n] = 0;
            }
        }
    }

//to fill the middle boxes - 
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s[i-1] == b[j-1]){ //if the values are equal
                t[i][j] = 1 + t[i-1][j-1];
            }else{ //if not
                t[i][j] = max(t[i][j-1] , t[i-1][j]);
            }
        }
    }


    return t[m][n];
}

int longestPalindromeSubseq(string s){
    //create string b - 
    string b = s;
    reverse(b.begin() , b.end());
    int m = s.size();
    int n = b.size();
    return LCS(s , b , m , n);
}

int main(){
    string s = "agbcba";

    cout << longestPalindromeSubseq(s);
}