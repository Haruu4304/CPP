/*
here we can't keep complex pairs in unordered_set
and here implitations is done with hash values

lets see the question on unordered Set - 
Q - Given N strings and Q queries.
In each query you are given a string print yes if string is present
else print no.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_set<string> s;
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        s.insert(str); //O(1)
    }

    cout << "Enter the string that you want to check - " << endl;
    string value;
    cin >> value;

    auto it = s.find(value); //O(1)
    if(it != s.end()){
        cout << "Yes, the string is present" << endl;
    }else{
        cout << "No, the string is not present" << endl;
    }
}