/*
Problem Statement : Shortest Common SuperSequence 
here supersequence -> character must come in a specific order(sequence) if it is not continues it will work
here -> we have given 2 string 
        and that 2 string we have to merge in a superSequence manner and return the minimum one.
*/

#include<bits/stdc++.h>
using namespace std;

int LCS(string s1 , string s2 , int m , int n){
    vector<vector<int>> t (m+1 , vector<int>(n+1 , 0)); //matrix 

//to fill the middle boxes - 
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s1[i-1] == s2[j-1]){ //if the values are equal
                t[i][j] = 1 + t[i-1][j-1];
            }else{ //if not
                t[i][j] = max(t[i][j-1] , t[i-1][j]);
            }
        }
    }


    return t[m][n];
}


int shortestCommonSupersequence(string &s1 , string &s2){
    int m = s1.size();
    int n = s2.size();

    int result = m + n - LCS(s1 , s2 , m , n);
    return result;
}

int main(){
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    cout << shortestCommonSupersequence(s1 , s2) << endl;
}