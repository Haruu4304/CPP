#include<bits/stdc++.h>
using namespace std;

void printMap(unordered_map<char,int> mp){
    for(auto &value : mp){
        cout << value.first << " " << value.second << endl;
    }
}

void mostFreq(string s){
    unordered_map<char, int> mp;
    for(int i=0; i<s.length(); ++i){
        mp[s[i]]++;
    }
    // printMap(mp);
    for(auto &value : mp){
        if(value.second > 1){
            cout << value.first << " " << value.second << endl;
        }
    }
}

int main(){
    string s;
    getline(cin, s);
    mostFreq(s);
}