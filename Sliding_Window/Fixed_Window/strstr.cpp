/*
Problem Statement - 
Given two strings needle and haystack, return the index of the first 
occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

#include<bits/stdc++.h>
using namespace std;

//brute force method implementation -  O(n^2)
// int bruteForceMethod(string str1, string str2){
//     for(int i=0; i<str1.size(); i++){
//         for(int j=0; j<str1.size(); j++){
//             if(str2[i] == str[i]){
//                 return 1;
//             }else{
//                 return -1;
//             }
//         }
//     }
// }

//optimization code - 
int strstr(string str1, string str2){
    int m = str1.size();
    int n = str2.size();

    //base condition
    if(n == 0){
        return 0;
    }
    if(n > m){
        return -1;
    }

    for(int i=0; i <= m-n; ++i){
        int j=0;
        while(j<n && str1[i + j] == str2[j]){
            j++;
        }
        if(j==n){
            return i;
        }
    }

    return -1;
}

int main(){
    string str1;
    string str2;

    getline(cin, str1);
    getline(cin, str2);

    // int result = bruteForceMethod(str1, str2);

    int output = strstr(str1, str2);

    cout << output <<" ";
}