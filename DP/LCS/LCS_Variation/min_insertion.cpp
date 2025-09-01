/*
minimum number of insertion to make a string palindrome - 
*/
#include<bits/stdc++.h>
using namespace std;
//logic of longest common subsequence - 
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


int LPS(string s){
    string b = s;
    reverse(b.begin(), b.end()); //we created another string

    //now we will apply LCS
    int m = s.size();
    int n = b.size();
    int resultLCS = LCS(s , b , m , n);

    return (m - resultLCS);
} 

int minInsertions(string &s){
    int result = LPS(s);
    return result;
}

int main(){
    string s = "zzazz";
    cout << minInsertions(s);
}