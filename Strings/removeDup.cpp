/*
Question 5 - 
Remove Duplicates from a string - 
*/
#include<bits/stdc++.h>
using namespace std;

void removeDuplicates(string s){
    unordered_map<char, int> lastpos;

    //step 1 - 
    for(int i=0; i<s.length(); ++i){
        lastpos[s[i]] = i;
    }

    //step 2 - 
    string result = "";
    for(int i=0; i<s.length(); ++i){
        if(lastpos[s[i]] == i){
            result+=s[i];
        }
    }
    cout << "output : " << result << endl;
}

int main(){
    string s;
    getline(cin, s);
    removeDuplicates(s);
}