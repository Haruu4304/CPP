/*
Problem Statement : 
minimum number of insertion and deletion to convert string A to string B.
*/

#include<bits/stdc++.h>
using namespace std;

int LCS(string s1 , string s2, int m , int n){
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
            if(s1[i-1] == s2[j-1]){ //if the values are equal
                t[i][j] = 1 + t[i-1][j-1];
            }else{ //if not
                t[i][j] = max(t[i][j-1] , t[i-1][j]);
            }
        }
    }


    return t[m][n];
}

int minInsertionDeletion(string s1 , string s2){
    int m = s1.size();
    int n = s2.size();

    int noOfDeletion = m - LCS(s1 , s2 , m , n);
    int noOfInsertion = n - LCS(s1 , s2 , m , n);

    return (noOfDeletion + noOfInsertion);
}

int main(){
    string a = "heap";
    string b = "pea";

    cout << minInsertionDeletion(a , b);

    return 0;
    
}