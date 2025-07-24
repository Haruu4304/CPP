/*
substrings of strings - 
*/

#include<bits/stdc++.h>
using namespace std;

void checkString(string str){
    string temp = "";
    for(int i=0; i<str.length(); ++i){
        for(int j=i; j<str.length(); ++j){
            temp+=str[j];
            cout << temp << endl;
        }
        temp = "";
    }
}

int main(){
    string str = "abc";
    checkString(str);
}