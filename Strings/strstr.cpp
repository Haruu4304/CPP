#include<bits/stdc++.h>
using namespace std;

void printSub(int temp, string s1){
    for(int i=0; i<te)
}

void checkSubstring(string s1, string s2){
    int i=0;
    int j=0;
    int temp;
    while(j<i){
        if(s1[i] == s2[j]){
            temp = i;
            i++;
            j++;
        }else{
            i++;
            j = 0;
        }
    }

    printSub(temp);
}


int main(){
    string s1 = "shahar";
    string s2 = "har";

    checkSubstring(s1,s2);
}