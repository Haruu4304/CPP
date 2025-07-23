/*
Question 1 - Reverse a strings 
*/

#include<bits/stdc++.h>
using namespace std;

void reverseString(string s){
    reverse(s.begin() , s.end());
    cout << s;
}

int main(){
    string s;
    cin >> s;
    cout << s << endl;

    //reverse 
    reverseString(s);
    return 0;
}