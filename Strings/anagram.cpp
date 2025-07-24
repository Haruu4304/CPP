/*
check whether it is anagram or not - 
ex., 1. listen -> silent 
     2. race -> care
*/

#include<bits/stdc++.h>
using namespace std;

void checkAnagram(string s1, string s2){
    map<char, int> mp;
    //here we will increment the frequencies of element for each char - 
    for(auto c : s1){
        mp[c]++;
    }

    //here we will decrement the elements frequencies -
    for(auto c: s2){
        mp[c]--;
    }

    //now check whether the all freq having 0 
    for(auto c : mp){
         if (c.second != 0) {
            cout << "No, it is not an anagram";
            return;
        }
    }
    cout << "Yes it is anagram";
}

//new anagram question - 
/*
Group Anagrams
Given: An array of strings strs.
Task: Group the strings that are anagrams of each other.
*/

vector<vector<string>> GroupAnagram(vector<string> &str) {
    unordered_map<string, vector<string>> mp;
    for (auto ss : str) {
        string sorted_s = ss;
        sort(sorted_s.begin(), sorted_s.end());
        mp[sorted_s].push_back(ss);
    }

    vector<vector<string>> result;
    for (auto c : mp) {
        result.push_back(c.second);
    }
    return result;
}

vector<int> findAllAnagrams(string s, string p){
    int n = s.size();
    int m = p.size();
    vector<int> result;

    // Base case 
    if(n < m){
        return result;
    }

    // Sort p string 
    string sorted_p = p;
    sort(sorted_p.begin(), sorted_p.end()); // klgk

    for(int i = 0; i <= n - m; i++){        // n-m
        string window = s.substr(i, m);
        sort(window.begin(), window.end()); // n-m * klgk

        if(window == sorted_p){
            result.push_back(i);
        }
    }

    return result;
}

int main(){
    // string s1, s2;
    // cin >> s1 >> s2;
    // checkAnagram(s1, s2);
    int n;
    cin >> n;
    vector<string> ss;
    vector<vector<string> > result;
    for(int i=0; i<n; i++){
        string value;
        cin >> value;
        ss.push_back(value);
    }

    result = GroupAnagram(ss);
    for(auto group : result){
        for(auto word : group){
            cout << word << " ";
        }
        cout << endl;
    }
}