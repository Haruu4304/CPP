/*
here we are trying to do memorization : 
*/

#include<bits/stdc++.h>
using namespace std;

int LCS(string x ,string y , int n , int m){
    //base cond.
    if(n == 0 || m == 0){
        return 0;
    }

    vector<vector<int>> t(n+1 , vector<int>(m+1 , -1)); //here we initilize the t matrix 

    if(t[n][m] != -1){
        return t[n][m];
    }else{
        if(x[n-1] == y[m-1]){ //if x string and y string last element is same 
            t[n][m] = 1+LCS(x , y , n-1 , m-1);
        }else{
            t[n][m] = max(LCS(x , y , n , m-1)  , 
                            LCS(x , y , n-1 , m));
        }
    }

    return t[n][m];
}

int main(){
    string x = "abcdfh";
    string y = "abedghr";
    int n = x.size();
    int m = y.size();
    cout << "Result : " << LCS(x , y , n , m);
}