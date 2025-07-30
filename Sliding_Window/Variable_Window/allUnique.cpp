/*
Longest substring with all unique characters - 
*/

#include<bits/stdc++.h>
using namespace std;

int longestSubAllUnique(vector<string> &s, int size){
    int i=0, j=0;
    unordered_map<string , int>mp;
    int ans = INT_MIN;
    while(j < size){
        mp[s[j]]++;

        //case II
        if(mp.size() == j-i+1){
            ans = max(ans , j-i+1);
            j++;
        }
        //case III
        else if(mp.size() < j-i+1){
            while(mp.size() < j-i+1){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    return ans;
}

int main(){
    vector<string> s;
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
        string x;
        cin >> x;
        s.push_back(x);
    }

    int result = longestSubAllUnique(s , n);

    cout << "Result : " << result;
}