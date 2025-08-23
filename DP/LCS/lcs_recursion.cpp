/*
so first we are doing here LCS -> Longest Commom Subsequence 
by using recursion method 
*/

#include<bits/stdc++.h>
using namespace std;

int LCS(string x , string y , int n , int m){
    //base condition 
    if(n == 0 || m == 0){
        return 0;
    }

    //choice diagram - 
    if(x[n-1] == y[m-1]){ //last char of string x and y are same 
        return 1 + LCS(x , y , n-1 , m-1);
    }else{
        return max(LCS(x , y , n , m-1) ,//here we are considering x as full and negalting y of n-1 element
                       LCS(x , y , n-1 ,m)); //here we are considering  y as full and negalting x of n-1 element
    }
}


int main(){
    string x = "";
    string y = "";
    int n = x.size(); //size of x string
    int m = y.size(); //size of y string
    cout << "Common Longest Subsequence between these 2 strings are : " <<LCS(x , y , n , m);
}