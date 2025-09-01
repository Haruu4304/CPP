#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> t;

int LCS(string s , string b , int m , int n){
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

string shortestCommonSupersequence(string &str1 , string &str2){
    int m = str1.size();
    int n = str2.size();
    string s = "";

    // Build LCS table first
    LCS(str1, str2, m, n);

    int i = m, j = n;

    // Backtrack to construct SCS
    while(i > 0 && j > 0){
        if(str1[i-1] == str2[j-1]){
            s.push_back(str1[i-1]);
            i--;
            j--;
        }else{
            if(t[i][j-1] > t[i-1][j]){
                s.push_back(str2[j-1]);
                j--;
            }else{
                s.push_back(str1[i-1]);
                i--;
            }
        }
    }

    // Add remaining characters
    while(i > 0){
        s.push_back(str1[i-1]);
        i--;
    }
    while(j > 0){
        s.push_back(str2[j-1]);
        j--;
    }

    reverse(s.begin(), s.end());
    return s;
}

int main(){
    string str1 = "acbcf";
    string str2 = "abcdaf";
    int m = str1.size();
    int n = str2.size();
    t.assign(m+1 , vector<int>(n+1 , 0));
    cout << shortestCommonSupersequence(str1, str2);
}
