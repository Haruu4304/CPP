/*
LCS - top down approach - 
*/

#include<bits/stdc++.h>
using namespace std;

int LCS(string x , string y , int n , int m){

    vector<vector<int>> t (n+1 , vector<int>(m+1 , 0)); //matrix 

    //initilization
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i == 0 || j == 0){
                t[n][m] = 0;
            }
        }
    }

//to fill the middle boxes - 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(x[n-1] == y[m-1]){ //if the values are equal
                t[i][j] = 1 + t[i-1][j-1];
            }else{ //if not
                t[i][j] = max(t[i][j-1] , t[i-1][j]);
            }
        }
    }


    return t[n][m];
}

int main(){
    string x = "abcf";
    string y = "abcdaf";
    int n = x.size();
    int m = y.size();
    cout << "Result : " << LCS(x , y , n , m);
}